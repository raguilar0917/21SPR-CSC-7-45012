/*
    Dr. Mark E. Lehr
    CSC 7 Template for Mastermind AI
    May 11th, 2021
 */
//final
//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

//Function Prototypes
string AI(char,char);
string myAI(char, char);
bool eval(string,string,char &,char &);
string set();
int toInt(char num){return (num - '0');}
char toChar(int num){return num+'0';}
void swap(char*, char*);
void printRR(char rr[], char rw[]){
    for(int i = 0; i < 30; i++){
        cout<<i<<": "<<to_string(rr[i])<<" " << to_string(rw[i])<<endl;
    }
}
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    string code,guess;  //code to break, and current guess
    char rr,rw;         //right digit in right place vs. wrong place
    int nGuess;         //number of guesses
    
    //Initialize Values
    nGuess=0;
    code="5921";//set();
    rr=rw=0;
    
    //Loop until solved and count to find solution
    cout<<"Code: " << code << endl;
    do{
       nGuess++;
       guess=myAI(rr,rw);
       string RR=to_string(rr), RW=to_string(rw);
       cout<<nGuess<<": YOUR INPUT "<<guess<<" "<<RR<<" "<< RW <<endl;
       if(!(nGuess % 30)){int a; cin>>guess;}
       //cout<<guess<<endl;
    }while(eval(code,guess,rr,rw));
    //Check evaluation
    cout<<nGuess<<" "<<code<<" "<<guess<<endl;
    guess=myAI(rr,rw);
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

void swap(char* val1, char* val2){
    char temp = *val1;
    *val1 = *val2;
    *val2 = temp;
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
    static const int SIZE=10000;//How many guesses to save
    static string aGuess[SIZE]; //Save the guesses
    static char grr[SIZE];      //Save right guess in right spot
    static char grw[SIZE];      //Save right guess in wrong spot
    static int guess=0;         //Increment the guess number
    string sGuess="0000";       //Size the guest string
    
    //Store the results from the last guess
    grr[guess]=rr;
    grw[guess]=rw;
    
    //Test the helper function
    if(rr==4)print(aGuess,grr,grw,
            guess-10>0?guess-10:0,guess);
    
    //Calculate the guess
    int n1000=(guess-guess%1000)/1000;
    int n100=(guess-guess%100)/100-10*n1000;
    int n10=(guess%100-guess%10)/10;
    int n1=guess%10;
    sGuess[0]=n1000+'0';
    sGuess[1]=n100+'0';
    sGuess[2]=n10+'0';
    sGuess[3]=n1+'0';
    aGuess[++guess]=sGuess;//Save the result
    
    //Return the result
    return sGuess;
}



string myAI(char rr, char rw){
    //Save the historical values of guesses and results
    static bool firstTwo = false;
    static bool dupes = false;
    static  string otherTwo = "00";
    //static int pos[2];
    static string finalGuess = "0000";
    static int valIndx[2];
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
    //for(int i = 0; i < guess; i++){
    //    cout<<to_string(grr[i])<<" "<<to_string(grw[i])<<endl;
    // }
    
        
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
        cout<<"POS "<<pos<<endl;
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
    }
    else{
        if(guess == 10){
            sGuess = confirmedCols;//XXXX
        }

        if(guess == 11 && !firstTwo){
                sGuess[0] = confirmedCols[0];
                sGuess[1] = confirmedCols[1];
                valIndx[0] = 0;
                valIndx[1] = 1;

                //saves other two
                otherTwo[0] = confirmedCols[2];
                otherTwo[1] = confirmedCols[3];

                sGuess[2] = badNums[0];
                sGuess[3] = badNums[0];



                //XY-- or XX--
        }

        if(guess == 12 && !firstTwo){//first swap
            sGuess = aGuess[guess];
            cout<<"Before: "<<sGuess<<endl;

            if(rr == 2){ 
                finalGuess = sGuess;
                firstTwo = true;
            }
            if(sGuess[0] == sGuess[1]){
                cout<<"enter dupe 1"<<endl;
                swap(sGuess[3], sGuess[1]);//X00X
                cout<<"After: "<<sGuess<<endl;
                dupes = true;
            }
            else{
                cout<<"rr: "<< to_string(rr)<<" rw: "<<to_string(rw)<<endl;
                if((rr == 1 && rw == 1) || (rr == 0 && rw == 2)){
                    cout<<"entered 12"<<endl;
                    swap(sGuess[0], sGuess[1]);//YX--
                    
                }
                
            }
            
        }
        if(guess == 13 && !firstTwo){//second spread
            sGuess = aGuess[guess];
            cout<<"after dupe 1: "<<sGuess<<endl;
            if(rr == 2){ 
                finalGuess = sGuess;
                firstTwo = true;
            }
            if((sGuess[0] == sGuess[3]) && dupes){
                cout<<"enter dupe 2"<<endl;
                swap(sGuess[0], sGuess[1]);//0X0X
            }
            else{
                if((rr == 1 && rw == 1) || (rr == 0 && rw == 2)){
                    cout<<"entered 13A"<<endl;
                    swap(sGuess[1], sGuess[3]);//Y--X
                }
                if((rr == 0 && rw == 2) && (grr[guess-1] == 1 && grw[guess-1] == 1)){
                    cout<<"entered 13B"<<endl;
                    sGuess = aGuess[guess-1];
                    swap(sGuess[1], sGuess[3]);//X--Y
                }
            }
        }
        if(guess == 14 && !firstTwo){//swap  left inch
            sGuess = aGuess[guess];

            if(rr == 2 && !firstTwo){ 
                finalGuess = sGuess;
                firstTwo = true;
            }
            if((sGuess[1] == sGuess[3]) && dupes){
                swap(sGuess[2], sGuess[3]);//0XX0
            }
            else{
                if((rr == 1 && rw == 1)){
                    cout<<"entered 14A"<<endl;
                    swap(sGuess[0], sGuess[1]);//-Y-X or -X-Y
                }
                if((rr == 0 && rw == 2)){
                    cout<<"entered 14B"<<endl;
                    swap(sGuess[0], sGuess[3]);//X--Y
                }
            }
        }
        if(guess == 15 && !firstTwo){//swap  right inch
            sGuess = aGuess[guess];

            if(rr == 2){ 
                finalGuess = sGuess;
                firstTwo = true;
            }
            if((sGuess[1] == sGuess[2]) && dupes){
                swap(sGuess[0], sGuess[1]);//X0X0
            }
            else{
                if((rr == 1 && rw == 1)){
                    cout<<"entered 15A: "<<sGuess<<endl;
                    swap(sGuess[2], sGuess[3]);//-YX- or X-Y-
                }
                if((rr == 0 && rw == 2) && (grr[guess] == 1 && grw[guess] == 1)){
                    cout<<"entered 15B"<<endl;
                    sGuess = aGuess[guess-1];
                    swap(sGuess[2], sGuess[3]);//Y-X-
                }else{
                    if(rr == 0 && rw == 2){
                        cout<<"entered 15C"<<endl;
                        swap(sGuess[0], sGuess[1]);//-X-Y
                    }
                }
            }
        }
        if(guess == 16 && !firstTwo){//swap  right inch
            sGuess = aGuess[guess];

            if(rr == 2){ 
                finalGuess = sGuess;
                firstTwo = true;
            }
            if((sGuess[0] == sGuess[2]) && dupes){
                swap(sGuess[0], sGuess[1]);//0X0X
                swap(sGuess[2], sGuess[3]);

            }

            else{
                if((rr == 1 && rw == 1)){
                    cout<<"entered 16A"<<sGuess<<endl;
                    swap(sGuess[1], sGuess[2]);//-YX- or X-Y-
                }
                if((rr == 0 && rw == 2) && (grr[guess-1] == 1 && grw[guess-1] == 1)){
                    cout<<"entered 16B: "<<sGuess<<endl;
                    sGuess = aGuess[guess-1];
                    cout<<"in 16B: "<<sGuess<<endl;
                    swap(sGuess[3], sGuess[2]);//Y-X-
                }
            }
        }
        
        if(guess == 17 && !firstTwo){//swap  right inch
            sGuess = aGuess[guess];

           // printRR(grr, grw);
            if(rr == 2){ 
                finalGuess = sGuess;
                firstTwo = true;
            }
            if((sGuess[0] == sGuess[2]) && dupes){
                swap(sGuess[2], sGuess[3]);
                swap(sGuess[0], sGuess[2]);//0X0X
                

            }

            else{
                if((rr == 1 && rw == 1)){
                    cout<<"entered 17A"<<endl;
                    swap(sGuess[3], sGuess[2]);//-YX- or X-Y-
                }
                if((rr == 0 && rw == 2) && ((grr[guess-1] == 1 && grw[guess-1] == 1))){
                    cout<<"entered 17B: "<<sGuess<<endl;
                    sGuess = aGuess[guess-1];
                    cout<<"entered 17B: "<<sGuess<<endl;
                    cout<<sGuess<<endl;
                    swap(sGuess[3], sGuess[2]);//Y-X-
                }else{
                    if((rr == 0 && rw == 2)){
                        cout<<"entered 17c"<<endl;
                       // swap(sGuess[2], sGuess[3]);//Y-X-
                    }
                }
            }
        }
        /***
        if(guess == 18 && !firstTwo){//swap  right inch
            sGuess = aGuess[guess];

            if(rr == 2){ 
                finalGuess = sGuess;
                firstTwo = true;
            }
            if((sGuess[0] == sGuess[2]) && dupes){
                swap(sGuess[0], sGuess[1]);//0X0X
                swap(sGuess[2], sGuess[3]);

            }

            else{
                if((rr == 1 && rw == 1)){
                    cout<<"entered 17A"<<endl;
                    swap(sGuess[3], sGuess[2]);//-YX- or X-Y-
                }
                cout<<"rr: "<< to_string(rr)<<" rw: "<<to_string(rw)<<endl;
                cout<<"rr: "<< to_string(grr[guess-2])<<" rw: "<<to_string(grw[guess-2])<<endl;
                
                if((rr == 0 && rw == 2) && (grr[guess-2] == 1 && grw[guess-2] == 1)){
                    cout<<"entered 17B"<<endl;
                    sGuess = aGuess[guess-2];
                    swap(sGuess[1], sGuess[2]);//Y-X-
                }else{
                    if((rr == 0 && rw == 2)){
                        cout<<"entered 17c"<<endl;
                       // swap(sGuess[2], sGuess[3]);//Y-X-
                    }
                }
            }
        }
        ***/
    }
    
    
 
    
   /***
    //Calculate the guess
    int n1000=(guess-guess%1000)/1000;
    int n100=(guess-guess%100)/100-10*n1000;
    int n10=(guess%100-guess%10)/10;
    int n1=guess%10;
    sGuess[0]=n1000+'0';
    sGuess[1]=n100+'0';
    sGuess[2]=n10+'0';
    sGuess[3]=n1+'0';
    
    
     * * */
    
    aGuess[++guess]=sGuess;//Save the result
            
    
    cout<<endl<<"Confirmed Number: "<<confirmedCols<<endl;
    cout<<"Previous Response: "<<aGuess[guess-1]<<endl;
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
