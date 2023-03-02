#include <iostream>
#include <stdlib.h>

using namespace std;

void printString(char cString[], int size);
void printStringPointer(char *cString);

int main(void) {

	srand(time(0));

	const int wordSize = 15;
	char godWord[wordSize+1];

	for (int i = 0; i < wordSize; i++) {
		godWord[i] = (rand() % 26) + 97;
	}

	godWord[wordSize] = '\0';

	printString(godWord, wordSize);
	char* godPointer = godWord;
	printStringPointer(godPointer);


	return 0;
}

void printString(char cString[], int size) {

	cout << "Reading String at address: " << (int)&cString << endl;
	for (int i = 0; i < size; i++) {
		cout << (int)&cString[i] << ": " << cString[i] << endl;
	}
	cout << endl;

}

void printStringPointer(char* cString) {
	cout << "Reading String at address: " << (int)&cString << endl;
	char* ptr = cString;
	while (*ptr != '\0') {
		cout <<  (int)ptr << ": " << *ptr << endl;
		ptr++;
	}
	cout << endl;
}