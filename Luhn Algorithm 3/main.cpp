#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// each value is associated with the brands BIN number to be identified
enum CrdCard { American_Express = 34, Visa = 4, Discover = 6011, MasterCard = 54 };


bool validCC(string); // Luhn Checker
void flipDigit(string, CrdCard); // Flips Two Digits at two ransom positions without affecting the BIN number
void swap(char*, char*); // Helper function to swap character adjaciently 
void transpose(string, CrdCard); // Transposes a digit with an adjacent digit while not affecting BIN number
void flip_Transpose(string, CrdCard);
string genCC(CrdCard);// Generates 4 differnt brands of cards and uses their respective BIN


int main(int argc, char** argv) {
    //random seed
    srand(time(0));
    string card; // card number placeholder
    CrdCard brand; // card brand placeholder
    int flag; // User input flag
    
    // do while loop to prevent faulty input
    do {
        //basic CLI UI
        cout << "Please choose the brand of card you will get data on:" << endl;
        cout << "1. Visa\n2. American Express\n3. Discover\n4. MasterCard\n5. Random Card" << endl;
        cout << ':';
        cin >> flag;
        //if they choose random card a card will be randomly generated
        if (flag == 5) flag = (rand() % 4) + 1;

        //based on the answer the switch statement generates the properties
        switch (flag) {
        case 1:
            cout << "Visa";
            card = genCC(Visa);
            brand = Visa;
            break;
        case 2:
            cout << "American Express";
            card = genCC(American_Express);
            brand = American_Express;
            break;
        case 3:
            cout << "Discover";
            card = genCC(Discover);
            brand = Discover;
            break;
        case 4:
            cout << "MasterCard";
            card = genCC(MasterCard);
            brand = MasterCard;
            break;
        default:
            cout << "ERROR: INVALID INPUT" << endl;
        }
        cout << endl;

    } while (flag > 5 || flag < 1);

    // Output of the two function and the original data
    cout << "original card number: " << card << endl << endl;
    cout << "Transpose Function Data:" << endl;
    transpose(card, brand);

    cout << endl;

    cout << "Flip Two Digit Function Data: " << endl;
    flipDigit(card, brand);
    return 0;
}

string genCC(CrdCard brand) {
    srand(static_cast<int>(time(0)));
    string card = to_string(brand);
    switch (brand) {
    case 4:
        card += to_string((rand() % 90000) + 10000) + to_string((rand() % 90000) + 10000) + to_string((rand() % 90000) + 10000);
        return card;
        break;
    case 34:
        card += to_string((rand() % 9000) + 1000) + to_string((rand() % 90000) + 10000) + to_string((rand() % 9000) + 1000);
        return card;
        break;
    case 54:
        card += to_string((rand() % 9000) + 1000) + to_string((rand() % 90000) + 10000) + to_string((rand() % 90000) + 10000);
        return card;
        break;
    case 6011:
        card += to_string((rand() % 90000) + 10000) + to_string((rand() % 90000) + 10000) + to_string((rand() % 90) + 10);
        return card;
        break;
    default:
        return "none";
        break;
    }
    return " ";
}

//helper function for transpose  takes two char pointer and swaps them
void swap(char* num1, char* num2) {
    char temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void flipDigit(string card, CrdCard brand) {
    // random num seed
    srand(static_cast<int>(time(0)));
    //these are placeholders for the data that will be spit out
    int validCrds = 0;
    int invalidCrds = 0;
    //gets length of the card and subtracts one which will act as our MAX
    int len = card.length()-1;
    // gets the offset of the BIN which will act like our MIN
    int offset = to_string(brand).length();
    //for loop that flips a random digit 10000 times
    for (int i = 0; i < 10000; i++) {
        //getting two random position between the offset and the len
        int pos_one = (rand() % (len - offset + 1) + offset);
        int pos_two = (rand() % (len - offset + 1) + offset);

        //the while loop checks whther the first random position is equal to the second
        //if not it will coninue normally. if it is then it will randomly choose another 
        //position untill the condition is false
        while(pos_two == pos_one){ pos_two = (rand() % (len - offset + 1) + offset); }

        //sets the random position equal too a random number
        char digit_one = (rand() % 9 + 1) + '0';
        char digit_two = (rand() % 9 + 1) + '0';

        //setting the random positions too random numbers
        card[pos_one] = digit_one;
        card[pos_two] = digit_two;

        //increments the respective variable based if the card is valid or not
        (validCC(card) ? validCrds++ : invalidCrds++);
    }
    //spits out the data captured
    cout << "The number of valid cards is: " << validCrds << endl;
    cout << "The number of invalid cards is: " << invalidCrds << endl;
    cout << "The percentage of valid cards is: " << (validCrds / 10000.0) * 100.0 << '%' << endl;
    cout << "The percentage of invalid cards is: " << (invalidCrds / 10000.0) * 100.0 << '%' << endl;
}

void transpose(string card, CrdCard brand) {
    //random seed
    srand(static_cast<int>(time(0)));
    //place holders for the data
    int valid = 0, invalid = 0;
    //gets length
    int len = card.length() - 1;

    //gets offset to act as MIN
    int offset = to_string(brand).length();

    //Loops 10000 times
    for (int i = 0; i < 10000; i++) {
        // Gets a random position betweeb the len and the offset
        int pos_one = (rand() % (len - offset + 1) + offset);

        //if-statement that is asking if the random position is next to the offset (BIN #)
        //if so transpose with the rightside number to not affect the BIN #
        if (pos_one == offset) {
            swap(card[pos_one], card[pos_one+1]);
        }

        //if-statement asking if the position is at the Len or the last char in the array
        // if so transpose with the left-side number
        else if (pos_one == len) {
            swap(card[pos_one], card[pos_one-1]);
        }
        //if no other conditions meets transpose normally
        else {
            (i % 2 == 0) ? swap(card[pos_one], card[pos_one - 1]) : swap(card[pos_one], card[pos_one + 1]);
        }
        //luhn checker
        (validCC(card) ? valid++ : invalid++);
        

    }
    //spit out data
    cout << "The number of valid cards is: " << valid << "\nThe number of invalid cards is: " << invalid << "\nThe percentage of valid cards is : " << ((valid / 10000.0) * 100.0) << '%' << endl;
    cout << "The percentage of invalid cards is: " << (invalid / 10000.0) * 100.0 << '%' << endl;
}

bool validCC(string card) {
    int Digits = card.length();
    int Sum = 0, isSecond = false;
    for (int i = Digits - 1; i >= 0; i--) {
        int d = card[i] - '0';
        if (isSecond == true)
            d = d * 2;

        Sum += d / 10;
        Sum += d % 10;
        isSecond = !isSecond;
    }
    return (Sum % 10 == 0);
}