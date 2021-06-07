/*
    Dr. Mark E. Lehr
    CSC 7 Template for Mastermind AI
    May 11th, 2021
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

//Function Prototypes
string AI(char,char);
bool eval(string,string,char &,char &);
string set();

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    string code,guess;  //code to break, and current guess
    char rr,rw;         //right digit in right place vs. wrong place
    int nGuess;         //number of guesses
    
    //Initialize Values
    nGuess=0;
    code=set();
    rr=rw=0;
    int pause;
    cout<<"Code: "<<code<<endl;
    //Loop until solved and count to find solution
    do{
       nGuess++;
       guess=AI(rr,rw);
       cout<<nGuess<<": Your Input: "<<guess<<" "<<to_string(rr)<<" "<<to_string(rw)<<endl;
       if(!(nGuess % 30)){int a; cin>>a;}
    }while(eval(code,guess,rr,rw));
    //Check evaluation
    cout<<nGuess<<" "<<code<<" "<<guess<<endl;
    guess=AI(rr,rw);
    /*cout<<code<<endl;
    for(int i=0;i<10000;i++){
        guess=AI(0,0);
        eval(code,guess,rr,rw);
        cout<<setw(5)<<code<<setw(5)<<guess
                <<setw(2)<<static_cast<int>(rr)
                <<setw(2)<<static_cast<int>(rw)<<endl;
    }*/
    
    //Exit the program
    return 0;
}

string AI(char rr,char rw){
    //Define helper functions here
    void (*print)(string [],char [],char [],int,int)=
        [] (string g[],char r[],char w[],int nb,int ne){ 
            for(int i=nb;i<=ne;i++){
                cout<<g[i]<<" "
                    <<static_cast<int>(r[i])<<" "
                    <<static_cast<int>(w[i])<<endl;
            }
    };
    
    //Save the historical values of guesses and results
    static bool firstTwo = false;
    static bool dupe = false;
    static  string otherTwo = "00";
    //static int pos[2];
    static string finalGuess = "0000";
    static int pos = 0;
    static bool sameNum = false;
    static int bad_pos=0;
    static char badNums[10];
    static string confirmedCols = "0000";
    static const int SIZE=10000;//How many guesses to save
    static string aGuess[SIZE]; //Save the guesses
    static char grr[SIZE];      //Save right guess in right spot
    static char grw[SIZE];      //Save right guess in wrong spot
    static int guess=0;         //Increment the guess number
    string sGuess="0000";       //Size the guest string
    
    //Store the results from the last guess
    grr[guess]=rr;
    grw[guess]=rw;
    if(guess == 0){
        confirmedCols = "0000";
    }
    if(guess == 1){
        sGuess = "1111";
        if(rr == 0){ badNums[bad_pos++] = '0';}
        while(rr > 0){
            confirmedCols[pos++] = '0';
            rr--;
        }
        
    }
    if(guess == 2){
        if(rr == 0){ badNums[bad_pos++] = '1';}
        sGuess = "2222";
        while(rr > 0){
            confirmedCols[pos++] = '1';
            rr--;
        }
        
    }
    if(guess == 3){
        if(rr == 0){ badNums[bad_pos++]='2';}
        sGuess = "3333";
        while(rr > 0){
            confirmedCols[pos++] = '2';
            rr--;
        }
        
        
        
    }
    if(guess == 4){
        if(rr == 0){ badNums[bad_pos++]='3';}
        sGuess = "4444";
        while(rr > 0){
            confirmedCols[pos++] = '3';
            rr--;
        }
        
    }
    if(guess == 5){
        if(rr == 0){ badNums[bad_pos++] = '4';}
        sGuess = "5555";
        while(rr > 0){
            confirmedCols[pos++] = '4';
            rr--;
        }
        
    }
    if(guess == 6){
        if(rr == 0){ badNums[bad_pos++] = '5';}
        sGuess = "6666";
        while(rr > 0){
            confirmedCols[pos++] = '5';
            rr--;
        }
        
    }
    if(guess == 7){
        if(rr == 0){ badNums[bad_pos++]='6';}
        sGuess = "7777";
        while(rr > 0){
            confirmedCols[pos++] = '6';
            rr--;
        }
        
    }
    if(guess == 8){
        if(rr == 0){ badNums[bad_pos++]='7';}
        sGuess = "8888";
        while(rr > 0){
            confirmedCols[pos++] = '7';
            rr--;
        }
        
    }
    if(guess == 9){
        if(rr == 0){ badNums[bad_pos++] = '8';}
        sGuess = "9999";
        while(rr > 0){
            confirmedCols[pos++] = '8';
            rr--;
        }
        
        
        while(pos != 4){
            confirmedCols[pos++] = '9';
        }
    }
    
    if(firstTwo){
        cout<<"ENDGAME"<<endl;
        int indx = 0;
        sGuess = finalGuess;
        for(int i = 0; i < 4; i++){
            if(sGuess[i] == badNums[0]){
                sGuess[i] = otherTwo[indx++];
               
            }
        }
        swap(otherTwo[0], otherTwo[1]);
    }else{
        if(guess == 10){
            sGuess = confirmedCols;
        }
        if(guess == 11){
            sGuess[0] = confirmedCols[0];
            sGuess[1] = confirmedCols[1];

            //saves other two
            otherTwo[0] = confirmedCols[2];
            otherTwo[1] = confirmedCols[3];

            sGuess[2] = badNums[0];
            sGuess[3] = badNums[0];
        }
        if(guess == 12){
            sGuess = aGuess[guess];// gets guess from 11
            if(rr == 2){
                firstTwo = true;
                finalGuess = sGuess;
            }
            if(sGuess[0] == sGuess[1]){
                dupe = true;
                swap(sGuess[1], sGuess[3]);//X00X
                
            }else{
                if((rr==0&&rw==2)||(rr==1&&rr==1)){
                    swap(sGuess[0], sGuess[1]);
                }
            }
        }
        if(guess == 13){//spread out
            sGuess = aGuess[guess];// gets guess from 11
            if(rr == 2){
                firstTwo = true;
                finalGuess = sGuess;
            }
            if(dupe == true){
                swap(sGuess[0], sGuess[1]);//OX0X
            }else{
                if((rr==0&&rw==2)||(grr[guess-1]==1&&grr[guess-1]==1)){
                    sGuess = aGuess[guess-1];
                    swap(sGuess[1], sGuess[3]);//X--Y
                }else{
                    swap(sGuess[1], sGuess[3]);//y--X
                }
            }
        }
        if(guess == 14){//Fail safe
            sGuess = aGuess[guess];// gets guess from 11
            if(rr == 2){
                firstTwo = true;
                finalGuess = sGuess;
            }
          
            if(dupe == true){
                swap(sGuess[2], sGuess[3]);//OXXO
            }else{
                if((rr==0&&rw==2)){
                    sGuess = aGuess[guess-1];
                    swap(sGuess[1], sGuess[3]);//X--Y --> Y--X
                }else{
                    swap(sGuess[0], sGuess[1]);//y--X
                }
            }
        }
        if(guess == 15){//inch [0] <=> [1]
            sGuess = aGuess[guess];// gets guess from 11
            if(rr == 2){
                firstTwo = true;
                finalGuess = sGuess;
            }
          
            if(dupe == true){
                swap(sGuess[0], sGuess[1]);//X0X0
            }else{
                if((rr==0&&rw==2)){
                    sGuess = aGuess[guess-1];
                    swap(sGuess[0], sGuess[3]);
                    swap(sGuess[0], sGuess[1]);
                }else{
                    swap(sGuess[0], sGuess[1]);//y--X
                }
            }
        }
        if(guess == 16){//inch [3] <=> [2]
            sGuess = aGuess[guess];// gets guess from 11
            if(rr == 2){
                firstTwo = true;
                finalGuess = sGuess;
            }
          
            if(dupe == true){
                swap(sGuess[2], sGuess[3]);//X00X
                swap(sGuess[0], sGuess[2]);//00XX
            }else{
                swap(sGuess[0], sGuess[1]);
            }
        }
        if(guess == 17){//inch [0] <=> [1]
            sGuess = aGuess[guess];// gets guess from 11
            if(rr == 2){
                firstTwo = true;
                finalGuess = sGuess;
            }
          
            if(dupe == true){
                swap(sGuess[2], sGuess[3]);//OX0X
            }else{
                swap(sGuess[0], sGuess[1]);
            }
        }
        if(guess == 18){//inch [0] <=> [1]
            sGuess = aGuess[guess];// gets guess from 11
            if(rr == 2){
                firstTwo = true;
                finalGuess = sGuess;
            }
          
            if(dupe == true){
                swap(sGuess[2], sGuess[3]);//OX0X
            }else{
                swap(sGuess[1], sGuess[2]);
            }
        }
        if(guess == 19){//inch [0] <=> [1]
            sGuess = aGuess[guess];// gets guess from 11
            if(rr == 2){
                firstTwo = true;
                finalGuess = sGuess;
            }
            else{
                swap(sGuess[0], sGuess[3]);
            }
        }
        if(guess == 20){//inch [0] <=> [1]
            sGuess = aGuess[guess];// gets guess from 11
            if(rr == 2){
                firstTwo = true;
                finalGuess = sGuess;
            }else{
                swap(sGuess[0], sGuess[1]);
            }
        }
        if(guess == 21){//inch [0] <=> [1]
            sGuess = aGuess[guess];// gets guess from 11
            if(rr == 2){
                firstTwo = true;
                finalGuess = sGuess;
            }else{
                swap(sGuess[1], sGuess[2]);
            }
        }
        if(guess == 22){//inch [0] <=> [1]
            sGuess = aGuess[guess];// gets guess from 11
            if(rr == 2){
                firstTwo = true;
                finalGuess = sGuess;
            }else{
                swap(sGuess[3], sGuess[2]);
            }
        }
        if(guess ==23){
            sGuess = aGuess[guess];// gets guess from 11
            if(rr == 2){
                firstTwo = true;
                finalGuess = sGuess;
            }
        }
        
        
    }
    

    aGuess[++guess]=sGuess;//Save the result
    cout<<"cNums: "<<confirmedCols<<endl;
    //Return the result
    return sGuess;
}

bool eval(string code,string guess,char &rr,char &rw){
    string check="    ";
    rr=0,rw=0;
    //Check how many are right place
    for(int i=0;i<code.length();i++){
        if(code[i]==guess[i]){
            rr++;
            check[i]='x';
            guess[i]='x';
        }
    }
    //Check how many are wrong place
    for(int j=0;j<code.length();j++){
        for(int i=0;i<code.length();i++){
            if((i!=j)&&(code[i]==guess[j])&&(check[i]==' ')){
                rw++;
                check[i]='x';
                break;
            }
        }
    }
    
    //Found or not
    if(rr==4)return false;
    return true;
}

string set(){
    string code="0000";
    for(int i=0;i<code.length();i++){
        code[i]=rand()%10+'0';
    }
    return code;
}