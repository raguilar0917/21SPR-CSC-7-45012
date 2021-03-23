#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum CrdCard{American_Express = 34, Visa = 4, Discover = 6011, MasterCard = 54, ALL};


bool validCC(string);
void flipDigit(string);
string genCC(CrdCard);
bool luhnChk(string);
int main(int argc, char** argv) {
    srand(time(0));
    string card = genCC(Visa);
    cout<<card<<endl;
    //flipDigit(card);
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
    srand(time(0));
    char a = rand()%9+1 + '0';
    cout<<a<<endl;
    
    
    
    int len = card.length();
    char digit = (rand()%9)+1 + '0';
    int ranIndx = (rand()%len-1)+0;
    cout<<digit<<endl;
    
    card[ranIndx] = digit;
    cout<<card<<endl;
}
bool validCC(string card){
    int nDigits = card.length();
    int nSum = 0, isSecond = false;
    for (int i = nDigits - 1; i >= 0; i--) {
        int d = card[i] - '0';
        if (isSecond == true)
            d = d * 2;
        
        nSum += d / 10;
        nSum += d % 10;
        isSecond = !isSecond;
    }
    return (nSum % 10 == 0);
}
