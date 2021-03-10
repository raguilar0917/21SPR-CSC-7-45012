
#include <iostream>

using namespace std;
bool luhnChecker(string, int len);

int main(int argc, char** argv) {
    string card;
    cout<<"Please enter your card number (without spaces): ";
    cin>>card;
    
   
    luhnChecker(card, card.length())? (cout<<"Card Valid"<<endl) : (cout<<"Card Invalid"<<endl) ;%
    
    
    return 0;
}

bool luhnChecker(string card, int len){
    //initialize variable to sum total
    int sum = 0;
    // traverse through string 
    for(int i = 0; i < len; i++){
        // checks if i is an odd number 
        if( (i % 2) != 0 ){
            //checks if the value multiplied by two is greater than 9
            if(((card[i] - '0') * 2) > 9){
                // IF it is greater than 9 it separates the tenths and ones place and adds them to the sum
                sum += (((card[i] - '0') * 2)/10) + (((card[i] - '0') * 2)%10);
            }else{
                // if the doubling the value is not greater than 9 add the product too the sum
                sum+=(card[i]-'0')*2;
            }
        }else{
            //if  i isn't an odd value add the number to the sum
            sum+=card[i]-'0';
        }
    }
    //calculate checker number add too the sum
    sum += (sum*9)%10;
    
    //if sum mod 10 is 0 return true else the card is invalid
    if((sum%10)==0)
        return true;
    else
        return false;
}
