#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

void masterMind();
void printCode(char[], int);
bool inArray(char[], char, int);
void createCode(char[], int, char);
void enterGuess(char[], int);
void getResult(char code[], char guess[],char result[], int SIZE);
void simulation();
void getData(char[], int[]);
//the toInt and toChar helper functions were made because whenever
//I would use static_case<> it gave me wrong things
int toInt(char num){return (num - '0');}
char toChar(int num){return num+'0';}

int main(int argc, char** argv) {   
    char inp;
    //menu with a switch function to handle input 
    do{
        cout<<"Welcome to Mastermind, Please pick a mode: "
                <<"\n1. Simulation Mode"
                <<"\n2. Normal Game"<<endl;
        cin>>inp;
        
        switch(inp){
            case '1':
                simulation();
                break;
            case '2':
                masterMind();
                break;
            default:
                cout<<"INVALID INPUT"<<endl;
                break;
        }
    }while(inp < '1' || inp > '2');
    return 0;
}

void simulation(){
    char choice;
    //size of code
    int SIZE = 4;
    //initialization of code
    char code[SIZE];
    //initialize the guess array and input beginning 0's
    char guess[SIZE] = {'0', '0', '0', '0'};
    //result array to track data each increment
    //result[0] holds the number of correct characters in the correct position
    //result[1] holds the number of correct character in the incorrect position
    //result[2] holds the sum
    char result[3] = { '0', '0', '0'};
    // data array stores and updates data each turn
    //keeps track how many times the guess has certain amount of correct to incorrect numbers
    //data[0] to data[4] holds the data regarding how many times the right section gets a certain number
    //data[5] to data[9] holds the data regarding how many times the right but not right position section gets a certain number
    //dat[10] to data[14] holds the data regarding how many different sums there are
    int data[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    //asks to enter code or generate one
    do{
        cout<<"would you like a generated code or input your own?"
                <<"\n1. Generated"
                <<"\n2. Enter own"<<endl;
        cin>>choice;
        switch(choice){
            case '2':
                enterGuess(code, 4);
                break;
            case '1':
                createCode(code, SIZE, '0');
                break;
            default:
                cout<<"INVALID INPUT"<<endl;
                break;
        }
    }while(choice < '1' || choice > '2');
    //header prompt
    cout<<"        CODE          GUESS       #RIGHT   #RIGHT IN WRONG SPOT    SUM"<<endl;

    for(int i = 0; i < 10000; i++){
        //gets the result from array
        getResult(code, guess, result, SIZE);
        //based on the result the array holding data updates
        getData(result, data);
        //prints out the results of that turn
        cout<<i<<": ";
        printCode(code, 4);
        cout<<"    ";
        printCode(guess, 4);
        cout<<"       "<<result[0]<<"              "<<result[1]<<"               "<<result[2]<<endl;;
        
        // this string of if/else-if statements help increment the char array correctly 
        if(guess[0]=='9' && guess[1] == '9' && guess[2] == '9' && guess[3] == '9'){
            guess[3]++;
        }
        else if(guess[1] == '9' && guess[2] == '9' && guess[3] == '9'){
            guess[0]++;
            guess[1]='0';
            guess[2]='0';
            guess[3] = '0';
        }
        else if(guess[2] == '9' && guess[3] == '9'){
            guess[1]++;
            guess[2]='0';
            guess[3] = '0';
        }
        else if(guess[3] == '9'){
            guess[2]++;
            guess[3]='0';
        }else{
            guess[3]++;
        }
    }
    //prints out the data
    cout<<"Correct Number and Position"<<endl;
    cout<<"4 Right    3 Right    2 Right    1 Right   0 Right"<<endl;
    cout<<"    "<<data[0]<<"         "<<data[1]<<"        "<<data[2]<<"       "<<data[3]<<"       "<<data[4]<<endl;
    
    cout<<"Correct Number and incorrect Position"<<endl;
    cout<<"4 Right    3 Right    2 Right    1 Right   0 Right"<<endl;
    cout<<"    "<<data[5]<<"         "<<data[6]<<"        "<<data[7]<<"       "<<data[8]<<"       "<<data[9]<<endl;
    
    cout<<"Sum"<<endl;
    cout<<"4 Right    3 Right    2 Right    1 Right   0 Right"<<endl;
    cout<<"    "<<data[10]<<"         "<<data[11]<<"        "<<data[12]<<"       "<<data[13]<<"       "<<data[14]<<endl;
    
    
}

void masterMind(){
    int SIZE;
    char dupe;
    char result[2] = {'0', '0'};
    do{
        cout<<"Welcome to the game Mastermind!!! Here are the rules.\n"
                <<"1. the size chosen can only be from 4 to 8\n"
                <<"2. At the end of each turn you are given your result\n"
                <<"   The '+' character means you got a correct number on the correct position\n"
                <<"   The '-' character means you got an correct number on the incorrect position\n"
                <<"3. You are able to choose between a game with duplicates on or off"<<endl;
        cout<<"Please choose from 1 to 8 how many holes you want to play with: ";
        cin>>SIZE;
    }while(SIZE < 4 || SIZE > 8);
    do{
        cout<<"Would you like to enables duplicates?"
                <<"\n0. Disabled"
                <<"\n1. Enabled"<<endl;
        cin>>dupe;
        
    }while(dupe < '0' || dupe > '1');
    
    char guess[SIZE];
    char code[SIZE];
    createCode(code, SIZE, dupe);
    printCode(code, SIZE);
    short turn = 0;
    while(turn != 10 && result[0] != toChar(SIZE)){
        cout<<"=========TURN: "<<turn+1<<"=========="<<endl;
        enterGuess(guess, SIZE);
        turn++;
        printCode(guess, SIZE);
        getResult(code, guess, result, SIZE);
        cout<<"Result: " << result[0] << "  " << result[1] << endl;
    }
}

//prints the code
void printCode(char code[], int SIZE){
    cout<<"[ ";
    for(int i = 0; i < SIZE; i++){
        cout<<code[i]<<" ";
    }
    cout<<"]";
}

//checks if a number has been previously in an array
bool inArray(char code[], char num, int SIZE){
    for(int i = 0; i < SIZE; i++){
        if(code[i] == num){ return true; }
    }
    return false;
}

//creates a random num char array
void createCode(char code[], int SIZE, char dupe){
    srand(static_cast<unsigned int>(time(0)));
    if(dupe == '0'){
        for(int i = 0; i < SIZE; i++){
            code[i] = toChar((rand()%8)+1);
            while(inArray(code, code[i], i)){
                code[i] = toChar((rand()%8)+1);
            }
        }
    }else{
        for(int i = 0; i < SIZE; i++){
            code[i] = toChar((rand()%8)+1);
        }
    }
}

// gets data
void getData(char result[], int data[]){
    if(result[0] == '4'){data[0]++;}
    if(result[0] == '3'){data[1]++;}
    if(result[0] == '2'){data[2]++;}
    if(result[0] == '1'){data[3]++;}
    if(result[0] == '0'){data[4]++;}
    
    if(result[1] == '4'){data[5]++;}
    if(result[1] == '3'){data[6]++;}
    if(result[1] == '2'){data[7]++;}
    if(result[1] == '1'){data[8]++;}
    if(result[1] == '0'){data[9]++;}
    
    if(result[2] == '4'){data[10]++;}
    if(result[2] == '3'){data[11]++;}
    if(result[2] == '2'){data[12]++;}
    if(result[2] == '1'){data[13]++;}
    if(result[2] == '0'){data[14]++;}
}

void enterGuess(char guess[], int SIZE){
    for(int i = 0; i < SIZE; i++){
        cout<<"Please enter numbers between 1 and 9 no duplicates"<<endl;
        cout<<"Please enter hole #"<<i+1<<':';
        cin>>guess[i];
        while(guess[i] < '1' || guess[i] > '9'){
                cout<<"ERROR: INVALID NUMBER INPUTTED"<<endl;
                cout<<"PLEASE DO NOT ENTER ANYTHING LESS THAN 1 OR GREATER THAN 9"<<endl;
                cout<<"Please enter hole #"<<i+1<<':';
                cin>>guess[i];
           }
    }
}

void getResult(char code[], char guess[],char result[], int SIZE){
    int correct_pos = 0;
    int incorrect_pos = 0;
    //check for same position
    for(int i = 0; i < SIZE; i ++){
        if(code[i] == guess[i]){
            correct_pos++;
        }
    }
    
    //incorrect position tracker
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(code[i] == guess[j]){
                incorrect_pos++;
            }
        }
    }
    
    result[0] = toChar(correct_pos);
    result[1] = toChar(incorrect_pos - correct_pos);
    result[2] = toChar((incorrect_pos-correct_pos));
    
    
}