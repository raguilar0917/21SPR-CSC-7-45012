#include <iostream>
#include "GeneralHashFunctions.h"
using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    string str = "Then out spake brave Horatius, The Captain of the Gate: To every man upon this earth Death cometh soon or late. And how can man die better Than facing fearful odds, For the ashes of his fathers, And the temples of his gods.";
    cout<<str<<endl;
    cout<<"RS Hash: "<<RSHash(str)<<endl;
    cout<<"JS Hash: "<<JSHash(str)<<endl;
    cout<<"PJW Hash: "<<PJWHash(str)<<endl;
    cout<<"ELF Hash: "<<ELFHash(str)<<endl;
    cout<<"BKDR Hash: "<<BKDRHash(str)<<endl;
    cout<<"SDBM Hash: "<<SDBMHash(str)<<endl;
    cout<<"DJB Hash: "<<DJBHash(str)<<endl;
    cout<<"DEK Hash: "<<DEKHash(str)<<endl;
    cout<<"BP Hash: "<<BPHash(str)<<endl;
    cout<<"FNV Hash: "<<FNVHash(str)<<endl;
    cout<<"AP Hash: "<<APHash(str)<<endl;
    return 0;
}

