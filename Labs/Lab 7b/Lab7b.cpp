//Andrew Card

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <list>
using namespace std;

//Add up chars in string and mod by table size
int hashFunction(string ID, int tableSize) {

    //Convert to lowercase
    for (int i = 0; i < ID.length(); i++) {
        if (ID[i] >= 'A' && ID[i] <= 'Z') {
            ID[i] += 32;
        }
    }

    //Add up chars
    int sum = 0;
    for (int i = 0; i < ID.length(); i++) {
        sum += ID[i];
    }

    return sum % tableSize;
}

void simplePrintTable(list<string>[], int); //pass array and size

int main(void) {
	srand(time(0));
	const int tableSize = 3;

	// A c-type ARRAY of integer lists -- Want the indexing here.
	list<string> hashTable[tableSize];

    while(true){
        system("CLS");
	    
        //Take User String
        string input;
        cout << "Enter a string: ";
        getline(cin, input);

        //Hash the string
        int index = hashFunction(input, tableSize);

        //Add the string to the hash table
        hashTable[index].push_back(input);

        //print the hash table
	    simplePrintTable(hashTable, tableSize);

        //Ask user if they want to continue
        cout << "Continue? (y/n): ";
        char runAgain;
        cin >> runAgain;

        if(runAgain == 'n'){
            break;
        }

        cin.ignore();

    }
	return(0);
}

//Implementations
void simplePrintTable(list<string> arg[], int size) {
	// Print the buckets...
	list<string>::iterator myItr;

	for (int i = 0; i < size; i++) {
		cout << "bucket " << i << " ==> ";
		myItr = arg[i].begin();

		while (myItr != arg[i].end()) {
			cout << *myItr << ", ";
			myItr++;
		}
		cout << endl;
	}
}