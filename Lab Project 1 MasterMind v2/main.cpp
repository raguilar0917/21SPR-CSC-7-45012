#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void masterMind();
void printCode(int[], int);
bool inArray(int[], int, int);
void createCode(int[], int, int);
void enterGuess(int[], int, int);
string getResult(int[], int[], int);
int main(int argc, char** argv) {
    masterMind();
    return 0;
}

void masterMind(){
    int SIZE;
    int dupe;
    //prompt
    
    //do-while loop to detect invalid invalid inputs for the the size
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
    cout<<result<<endl;
    //generates the code
    createCode(code, SIZE, dupe);
    
    //game run
    short turns = 0;
    while(turns != 10 && result != win_result){
        cout<<"=========TURN: "<<turns+1<<"=========="<<endl;
        enterGuess(guess, SIZE, dupe);
        turns++;
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
    cout<<'[';
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
            while(inArray(guess, guess[i], i)){
                cout<<"ERROR: NUMBER ENTERED FOUND IN ARRAY"<<endl;
                cout<<"PLEASE DO NOT ENTER DUPLICATES"<<endl;
                cout<<"Please enter hole #"<<i+1<<':';
                cin>>guess[i];
            }
        }else{
            cout<<"Please enter numbers between 1 and 8"<<endl;
            cout<<"Please enter hole #"<<i+1<<':';
            cin>>guess[i];
        }
    }
}

string getResult(int code[], int guess[], int SIZE){
    
}