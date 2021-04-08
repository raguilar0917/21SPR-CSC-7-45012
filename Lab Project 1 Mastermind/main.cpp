#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;

enum pegColor { Red = 1, Green, Blue, Yellow, Brown, Orange, Black, White};
void printArr(char[], int);

void MasterMind();
pegColor* newGuess(pegColor[], char[]);
char* pegResult(pegColor [], pegColor []);

int main() {
	srand(static_cast<unsigned int>(time(0)));
                      int size; 
                      
                      
	pegColor num[4];
	pegColor num2[4];

	cout << "Guess: ";
	for (int i = 0; i < 4; i++) {
		num[i] = (pegColor)(rand() % 8 + 1);
		cout << num[i] << ' ';
	}
	
	cout << endl << "Code:  ";

	for (int i = 0; i < 4; i++) {
		num2[i] = (pegColor)(rand() % 8 + 1);
		cout << num2[i]<<' ';
	}
	char *result = pegResult(num, num2);
	cout << endl;
	printArr(result, 4);

} 
void MasterMind() {
    
}


void printArr(char arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}


char* pegResult(pegColor guess[], pegColor code[]) {

	unordered_map<pegColor, int> freq;

	for (int i = 0; i < 4; i++) {
		freq[code[i]]++;
	}
	char* result = new char[4];
	for (int i = 0; i < 4; i++) {
		result[i] = '_';
	}

	short array_pos = 0;
	short same_pos = 0;
	for (int i = 0; i < 4; i++) {
		if (freq[guess[i]] > 0) {
			result[array_pos] = '-';
			array_pos++;
			freq[guess[i]]--;
		}
	}
	array_pos = 0;
	for (int i = 0; i < 4; i++) {
		if(guess[i] == code[i]){
			result[array_pos] = '+';
			same_pos++;
			array_pos++;
		}
	}
	return (result);
}