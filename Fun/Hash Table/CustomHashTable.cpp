//Andrew Card

#include <iostream>

using namespace std;

//Hash Table Class
class HashTable{
    private:
        int size;
        int* table;
    public:
        HashTable(int size){
            this->size = size;
            table = new int[size];
            for(int i = 0; i < size; i++){
                table[i] = -1;
            }
        }
        void insert(int data){
            int index = data % size;
            while(table[index] != -1){
                index = (index + 1) % size;
            }
            table[index] = data;
        }
        void print(){
            for(int i = 0; i < size; i++){
                cout << table[i] << " ";
            }
            cout << endl;
        }
        //Get Size
        int getSize(){
            return size;
        }
        
        //Get Table
        int* getTable(){
            return table;
        }
};

//Search for a value in the hash table
bool search(HashTable* table, int data){
    int index = data % table->getSize();
    while(table->getTable()[index] != -1){
        if(table->getTable()[index] == data){
            return true;
        }
        index = (index + 1) % table->getSize();
    }
    return false;
}

int main(){

    //Create a hash table
    HashTable* table = new HashTable(10);

    //Insert some random values
    for(int i = 0; i < 100; i++){
        table->insert(rand() % 100);
    }

    //Print the table
    table->print();

    //Search for a value
    cout << search(table, 5) << endl;

    return 0;
}