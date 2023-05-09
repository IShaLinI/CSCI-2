//Andrew Card

#include <iostream>
#include <vector>

using namespace std;

//Student Class
class Student{
    private:
        string name;
        int id;
    public:
        Student(string name, int id){
            this->name = name;
            this->id = id;
        }
        string getName(){
            return name;
        }
        int getId(){
            return id;
        }
};

//Hash Table of Strudents
class HashTable{
    private:
        int size;
        Student** table;
    public:
        HashTable(int size){
            this->size = size;
            table = new Student*[size];
            for(int i = 0; i < size; i++){
                table[i] = NULL;
            }
        }
        void insert(Student* student){
            int index = student->getId() % size;
            table[index] = student;
        }
        Student* get(int id){
            int index = id % size;
            return table[index];
        }

        vector<int> getUsedIds(){
            vector<int> usedIds;
            for(int i = 0; i < size; i++){
                if(table[i] != NULL){
                    usedIds.push_back(table[i]->getId());
                }
            }
            return usedIds;
        }

        void print(){
            for(int i = 0; i < size; i++){
                if(table[i] != NULL){
                    cout << table[i]->getName() << endl;
                }
            }
        }

};

//Generate unique 5 digit id
int generateId(vector<int> usedIds){
    int id = rand() % 90000 + 10000;
    for(int i = 0; i < usedIds.size(); i++){
        if(id == usedIds[i]){
            return generateId(usedIds);
        }
    }
    return id;
}

int main(){
    
    //Student name bank
    string names[] = {"Andrew", "Bob", "Charlie", "David", "Ethan", "Frank", "George", "Henry", "Isaac", "John", "Kevin", "Larry", "Michael", "Nathan", "Oscar", "Peter", "Quentin", "Robert", "Steven", "Thomas", "Ulysses", "Victor", "William", "Xavier", "Yuri", "Zachary"};

    //Create Hash Table
    HashTable* table = new HashTable(5);

    //Insert 100 random students
    for(int i = 0; i < 10; i++){
        int id = generateId(table->getUsedIds());
        string name = names[rand() % 26];
        Student* student = new Student(name, id);
        table->insert(student);
    }

    //Print all students
    table->print();

    return 0;
}