#include <iostream>
#include <vector>

using namespace std;

void printIntVector(vector<int>);
void printIntVectorAddress(vector<int>);

int main(void) {

	vector<int> testVector = { 1,5,6,3,2,4,6,7,1 };

	printIntVector(testVector);
	printIntVectorAddress(testVector);


	return 0;
}

void printIntVector(vector<int> vector) {

	for (int i = 0; i < vector.size(); i++) {
		cout << "Element " << i + 1 << ":" << vector[i] << endl;
	}

	cout << endl;

}

void printIntVectorAddress(vector<int> vector) {
	cout << "Vector Address: " << (int)&vector << endl;

	for (int i = 0; i < vector.size(); i++) {
		cout << "\t Element " << i + 1 << ": " << (int)&vector[i] << endl;
	}
	cout << endl;
}