#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    bool p = true, q = false;
    cout<<"(p&&q) || !(p||q)  =  !(p^q)"<<endl;
    cout<<((p&&q)||!(p||q))?'T':'F';cout<<endl;
    cout<<(!(p^q))?'T':'F';
    return 0;
}

