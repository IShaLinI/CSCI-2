//Andrew Card

#include <iostream>
#include <string>

using namespace std;

string lowercase(string input){
    string output = "";
    for(int i = 0; i < input.length(); i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            output += input[i] + 32;
        }else{
            output += input[i];
        }
    }
    return output;
}

int stringToIndexHash(string input, int buckets){

    input = lowercase(input);

    int sum = 0;
    for(int i = 0; i < input.length(); i++){
        sum += input[i];
    }
    return sum % buckets;
}

//Hash Table Item
class HashTableItem{
    private:
        string key;
        int value;
    public:
        HashTableItem(string key, int value){
            this->key = key;
            this->value = value;
        }
        string getKey(){
            return key;
        }
        int getValue(){
            return value;
        }
};

class HashTable {
    private:
        int size;
        HashTableItem** table;
    public:
        HashTable(int size){
            this->size = size;
            table = new HashTableItem*[size];
            for(int i = 0; i < size; i++){
                table[i] = NULL;
            }
        }
        void insert(string key, int value){
            int index = stringToIndexHash(key, size);
            while(table[index] != NULL){
                index = (index + 1) % size;
            }
            table[index] = new HashTableItem(key, value);
        }
        void print(){
            for(int i = 0; i < size; i++){
                if(table[i] != NULL){
                    cout << table[i]->getKey() << " " << table[i]->getValue() << endl;
                }
            }
        }
        //Get Size
        int getSize(){
            return size;
        }
        
        //Get Table
        HashTableItem** getTable(){
            return table;
        }
};

//Sort hashtable
void sort(HashTable* table){

    //Create a new hash table
    HashTable* newTable = new HashTable(table->getSize());

    //Loop through the old table
    for(int i = 0; i < table->getSize(); i++){

        //If the item is not null
        if(table->getTable()[i] != NULL){

            //Insert into the new table
            newTable->insert(table->getTable()[i]->getKey(), table->getTable()[i]->getValue());

        }

    }

    //Delete the old table
    delete table;

    //Set the old table to the new table
    table = newTable;

}



int main(){

    //Create a hash table
    HashTable* table = new HashTable(20);

    while(true){

        system("CLS");

        //Get user string input.
        string name;
        cout << "Enter your name: ";
        getline(cin, name);

        //Get user's favorite number.
        int number;
        cout << "Enter your favorite number: ";
        cin >> number;

        //Insert into hash table
        table->insert(name, number);

        //Ask to run again
        cout << "More names? (y/n): ";
        char runAgain;
        cin >> runAgain;

        if(runAgain == 'n'){
            break;
        }

        cin.ignore();

    }

    //Print the hash table
    system("CLS");
    cout << "Unsorted Hash Table" << endl;
    table->print();

    //Sort the hash table
    sort(table);

    //Print the hash table
    cout << endl << "Sorted Hash Table" << endl;
    table->print();

    return 0;
}