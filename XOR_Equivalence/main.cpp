#include <iostream>

using namespace std;

void xOr_one(bool, bool);
void xOr_two(bool, bool);

int main(int argc, char** argv) {
    cout<<"p   q    p||q   p&&q  !(p&&q)  (p&&q)||~(p||q) = !(p^q)"<<endl;
    //first row for first table
    xOr_one(true, true);
    //second row for first table
    xOr_one(false, true);
    //third row for first table
    xOr_one(true, false);
    //fourth row for first table
    xOr_one(false, false);
//------------------------------------- 

    cout<<"p   q    p||q  p&&q  !(p||q)  (p||q)&&~(p&&q) = (p^q)"<<endl;
    //first row for first table
    xOr_two(true, true);
    //second row for first table
    xOr_two(false, true);
    //third row for first table
    xOr_two(true, false);
    //fourth row for first table
    xOr_two(false, false);
}
void xOr_one(bool p, bool q){
    cout<<(p?'T':'F')<<"   "
        <<(q?'T':'F')<<"      "
        <<(p||q?'T':'F')<<"      "
        <<(p&&q?'T':'F')<<"      "
        <<(!(p||q)?'T':'F')<<"             "
        <<(((p&&q)||!(p||q))?"T":"F")
        <<"           "
        <<(!(p^q)?'T':'F')<<endl;
}
void xOr_two(bool p, bool q){
    cout<<(p?'T':'F')<<"   "
        <<(q?'T':'F')<<"      "
        <<(p||q?'T':'F')<<"      "
        <<(p&&q?'T':'F')<<"      "
        <<(!(p&&q)?'T':'F')<<"             "
        <<(((p||q)&&!(p&&q))?"T":"F")
        <<"           "
        <<((p^q)?'T':'F')<<endl;
}