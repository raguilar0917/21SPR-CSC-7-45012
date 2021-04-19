#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

void masterMind();
void printCode(int[], int);
bool inArray(int[], int, int);
void createCode(int[], int, int);
void enterGuess(int[], int, int);
string getResult(int[], int[], int);
int main(int argc, char** argv) {
    cout<<"Welcome to the game Mastermind!!! Here are the rules.\n"
            <<"1. the size chosen can only be from 4 to 8\n"
            <<"2. At the end of each turn you are given your result\n"
            <<"   The '+' character means you got a correct number on the correct position\n"
            <<"   The '-' character means you got an correct number on the incorrect position\n"
            <<"3. You are able to choose between a game with duplicates on or off"<<endl;
    masterMind();
    return 0;
}

void masterMind(){
    int SIZE;
    int dupe;
    //prompt
    
    //do-while loop to detect invalid invalid inputs for the the size
    cout<<"Please enter the a size of pegs you want to play with from 4 and 8"<<endl;
    do{
        cout<<"SIZE: ";
        cin>>SIZE;
        if(SIZE>8||SIZE<4){ cout<<"INVALID: INPUT OUT OF BOUNDS"<<endl; }
    }while(SIZE>8||SIZE<4);
    
    //creates the string that result has to equal to win the game
    string win_result; 
    for(int i = 0; i < SIZE; i++){
        win_result += '+';
    }
    //do-while loop to catch invalid inputs for the duplication options
    cout<<"Please enter whether you want duplicates or not"<<endl;
    cout<<"0. Duplicates OFF"<<endl;
    cout<<"1. Duplicates ON"<<endl;
    do{
        //prompt
        cout<<"Duplicates: ";
        cin>>dupe;
        if(dupe<0||dupe>1){ cout<<"INVALID: INPUT OUT OF BOUNDS"<<endl; }
    }while(dupe<0||dupe>1);

    //create arrays to hold the guess and code
    int code[SIZE];
    int guess[SIZE];
    
    //string array for result
    string result;
    for(int i = 0; i < SIZE; i++){
        result += '_';
    }
    
    createCode(code, SIZE, dupe);
    
    //game run
    short turns = 0;
    while(turns != 10 && result != win_result){
        cout<<"=========TURN: "<<turns+1<<"=========="<<endl;
        enterGuess(guess, SIZE, dupe);
        turns++;
        printCode(guess, SIZE);
        result = getResult(code, guess, SIZE);
        cout<<"Result: " << result << endl;
    }
    if(result == win_result){
        cout<<"CONGRATS YOU WON!!"<<endl;
        cout<<"YOU WON IN " << turns << " TURNS"<< endl;
        cout<<"The winning code is: ";
        printCode(code, SIZE);
    }else{
        cout<<"YOU LOST :( "<<endl;
        cout<<"The correct code is: ";
        printCode(code, SIZE);
    }
    
}

void createCode(int code[], int SIZE, int dupe){
    srand(static_cast<unsigned int>(time(0)));
    if(dupe == 0){
        for(int i = 0; i < SIZE; i++){
            code[i] = (rand()%8)+1;
            while(inArray(code, code[i], i)){
                code[i] = (rand()%8)+1;
            }
        }
    }else{
        for(int i = 0; i < SIZE; i++){
            code[i] = (rand()%8)+1;
        }
    }
}

bool inArray(int code[], int num, int SIZE){
    for(int i = 0; i < SIZE; i++){
        if(code[i] == num){ return true; }
    }
    
    return false;
}

void printCode(int code[], int SIZE){
    cout<<"[ ";
    for(int i = 0; i < SIZE; i++){
        cout<<code[i]<<' ';
    }
    cout<<']'<<endl;
}

void enterGuess(int guess[], int SIZE, int dupe){
    
    for(int i = 0; i < SIZE; i++){
        if(dupe == 0){
            cout<<"Please enter numbers between 1 and 8 no duplicates"<<endl;
            cout<<"Please enter hole #"<<i+1<<':';
            cin>>guess[i];
            while(guess[i] < 1 || guess[i] > 8 || inArray(guess, guess[i], i)){
                cout<<"ERROR: INVALID NUMBER INPUTTED"<<endl;
                cout<<"PLEASE DO NOT ENTER DUPLICATES OR ANYTHING LESS THAN 1 OR GREATER THAN 8"<<endl;
                cout<<"Please enter hole #"<<i+1<<':';
                cin>>guess[i];
            }
        }else{
            cout<<"Please enter numbers between 1 and 8"<<endl;
            cout<<"Please enter hole #"<<i+1<<':';
            cin>>guess[i];
            while(guess[i] < 1 || guess[i] > 8 || inArray(guess, guess[i], i)){
                cout<<"ERROR: INVALID NUMBER INPUTTED"<<endl;
                cout<<"PLEASE DO NOT ENTER ANYTHING LESS THAN 1 OR GREATER THAN 8"<<endl;
                cout<<"Please enter hole #"<<i+1<<':';
                cin>>guess[i];
            }
        }
    }
}

string getResult(int code[], int guess[], int SIZE){
    unordered_map<int, int> freq;
    char result[SIZE];
    string str;
    for(int i = 0; i < SIZE; i++){
        freq[code[i]]++;
        result[i] += '_';
    }

    int arr_pos = 0;
    for(int i = 0; i < SIZE; i++){
        if(freq[guess[i]] > 0){
            result[arr_pos] = '-';
            arr_pos++;
            freq[guess[i]]--;
        }
    }

    arr_pos = 0;
    for(int i = 0; i < SIZE; i++){
        if(guess[i] == code[i]){
            result[arr_pos] = '+';
            arr_pos++;
        }
    }
    for(int i = 0; i < SIZE; i++){
        str += result[i];
    }
    cout<<endl;
    return str;
}