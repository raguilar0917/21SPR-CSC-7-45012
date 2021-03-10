#include <iostream>
using namespace std;

void absLaw(bool, bool);

int main(){
    cout<<"p  q  p||q   p&&(p||q)   p||(p&&q)"<<endl;
    absLaw(true, true);
    absLaw(true, false);
    absLaw(false, true);
    absLaw(false, false);

}
void absLaw(bool p, bool q){
    cout<<(p?'T':'F')<<"  "
        <<(q?'T':'F')<<"   "
        <<((p||q)?'T':'F')<<"         "
        <<(p&&(p||q)?'T':'F')<<"          "
        <<((p||(p&&q)?'T':'F'))<<endl;
}