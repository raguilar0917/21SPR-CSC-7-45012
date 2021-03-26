#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// each value is associated with the brands BIN number to be identified
enum CrdCard{American_Express = 34, Visa = 4, Discover = 6011, MasterCard = 54};


bool validCC(string);
void flipDigit(string);
string genCC(CrdCard);


int main(int argc, char** argv) {
    srand(time(0));
    string card;
    int flag;
    do{
        
       cout<<"Please choose the brand of card you will get data on:"<<endl;
       cout<<"1. Visa\n2. American Express\n3. Discover\n4. MasterCard\n5. Random Card"<<endl;
       cout<<':';
       cin>>flag;
       if(flag==5) flag=(rand()%3)+1;
       
       switch(flag){
           case 1:
               cout<<"Visa"<<endl;
               card = genCC(Visa);
               break;
           case 2:
               cout<<"American Express"<<endl;
               card = genCC(American_Express);
               break;
           case 3:
               cout<<"Discover"<<endl;
               card = genCC(Discover);
               break;
           case 4:
               cout<<"MasterCard"<<endl;
               card = genCC(MasterCard);
               break;
           default:
               cout<<"ERROR: INVALID INPUT"<<endl;
       }
       cout<<endl;
       
    }while(flag > 5 || flag < 1);
    cout<<"original card number: "<<card<<endl;
    flipDigit(card);
    return 0;
}


string genCC(CrdCard brand){
    srand(static_cast<int>(time(0)));
    string card = to_string(brand);
    switch (brand){
    case 4:
        card+=to_string((rand()%90000)+10000)+to_string((rand()%90000)+10000)+to_string((rand()%90000)+10000);
        return card;
        break;
    case 34:
        card+=to_string((rand()%9000)+1000)+to_string((rand()%90000)+10000)+to_string((rand()%9000)+1000);
        return card;
        break;
    case 54:
        card+=to_string((rand()%9000)+1000)+to_string((rand()%90000)+10000)+to_string((rand()%90000)+10000);
        return card;
        break;
    case 6011:
        card+=to_string((rand()%90000)+10000)+to_string((rand()%90000)+10000)+to_string((rand()%90)+10);
        return card;
        break;
    default:
        return "none";
        break;
    }
    return " ";
}
void flipDigit(string card){
    // random num seed
    srand(time(0));
    //these are placeholders for the data that will be spit out
    int validCrds = 0;
    int invalidCrds = 0;
    //gets length of the card
    int len  = card.length();
    //for loop that flips a random digit 10000 times
    for(int i = 0; i < 10000;i++){
        //getting a random position
        int pos = (rand()%len-1)+1;
        //sets the random position equal too a random number
        char  digit = (rand()%9+1) + '0';
        card[pos] = digit;
        
        //increments the respective variable based if the card is valid or not
        (validCC(card)?validCrds++:invalidCrds++);
    }
    //spits out the data captured
    cout<<"The number of valid cards is: "<<validCrds<<endl;
    cout<<"The number of invalid cards is: "<<invalidCrds<<endl;
    cout<<"The percentage of valid cards is: "<<(validCrds/10000.0)*100.0<<'%'<<endl;
}

//validates the card using the luhn algorithm
bool validCC(string card){
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
