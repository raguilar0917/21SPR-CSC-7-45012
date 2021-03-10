#include <iostream>

using namespace std;
//Using simple function to pass through bool values
//rather than variables. the function only outputs the result of the logic.
void truthTables(bool, bool);

int main(int argc, char** argv) {
    cout<<"X  Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
    
    
    //First Row
    truthTables(true, true);
    //Second Row
    truthTables(true, false);
    //Third Row
    truthTables(false, true);
    //fourth row
    truthTables(false, false);

    //Exit
    return 0;
}

void truthTables(bool x, bool y){
    cout<<(x?'T':'F')<<"  "
            <<(y?'T':'F')<<"  "
            <<(!x?'T':'F')<<"  "
            <<(!y?'T':'F')<<"  "
            <<(x&&y?'T':'F')<<"    "
            <<(x||y?'T':'F')<<"    "
            <<(x^y?'T':'F')<<"    "
            <<(x^y^x?'T':'F')<<"     "
            <<(x^y^y?'T':'F')<<"      "
            <<(!(x&&y)?'T':'F')<<"       "
            <<(!x||!y?'T':'F')<<"        "
            <<(!(x||y)?'T':'F')<<"      "
            <<(!x&&!y?'T':'F')
        <<endl;
}