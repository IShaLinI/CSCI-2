//Andrew Card

#include <iostream>
#include <vector>

using namespace std;

class Person{
    private:
        string name;

    public:
        Person(string _name){
            name = _name;
        }

        string getName(){
            return name;
        }
};

//Student Object inheriting person
class Student : public Person{
    private:
        int id;

        //Generate a unique 5 digit id with no leading 0s
        int generateId(vector<int> usedIds){
            int id = rand() % 100000;
            while(id < 10000){
                id = rand() % 100000;
            }
            for(int i = 0; i < usedIds.size(); i++){
                if(id == usedIds[i]){
                    id = generateId(usedIds);
                }
            }
            return id;
        }

    public:
        Student(string _name, vector<int> usedIds) : Person(_name){
            //Generate unique id
            id = generateId(usedIds);
        }

        int getId(){
            return id;
        }

        void print(){
            cout << "Name: " << getName() << endl;
            cout << "ID: " << getId() << endl;
        }
};

//Student name comparator class
class StudentNameComparator{
    public:
        bool operator()(Student s1, Student s2){
            return s1.getName() < s2.getName();
        }
};

//Student id comparator class
class StudentIdComparator{
    public:
        bool operator()(Student s1, Student s2){
            return s1.getId() < s2.getId();
        }
};

//Sort function for students using a generic comparator
template <class T>
void sort(vector<Student> &students, T comparator){
    for(int i = 0; i < students.size(); i++){
        for(int j = 0; j < students.size() - 1; j++){
            if(comparator(students[j], students[j + 1])){
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

//Hash Tabel Object
class HashTable{
    private:
        vector<Student> table[5];

        //Vector for storing used ids
        vector<int> usedIds;

        //Hash function
        int hash(string name){
            int sum = 0;
            for(int i = 0; i < name.length(); i++){
                sum += name[i];
            }
            return sum % 5;
        }

    public:

        //Add student to hash table
        void addStudent(Student s){
            int index = hash(s.getName());
            table[index].push_back(s);
            usedIds.push_back(s.getId());
        }

        //Print all students in hash table
        void print(){
            for(int i = 0; i < 5; i++){
                cout << "Bucket " << i << endl;
                for(int j = 0; j < table[i].size(); j++){
                    table[i][j].print();
                }
            }
        }

        //Search by name
        Student search(string name){
            int index = hash(name);
            for(int i = 0; i < table[index].size(); i++){
                if(table[index][i].getName() == name){
                    return table[index][i];
                }
            }
            return Student("Not Found", usedIds);
        }

        //Get used ids
        vector<int> getUsedIds(){
            return usedIds;
        }
};

int main(){

    srand(time(NULL));

    //List of student names
    string names[10] = {"Andrew", "Bob", "Charlie", "David", "Ethan", "Frank", "George", "Henry", "Isaac", "John"};

    //Create hash table
    HashTable ht;

    //Add students to hash table
    for(int i = 0; i < 10; i++){
        Student s(names[i], ht.getUsedIds());
        ht.addStudent(s);
    }

    //Compare Bob and Frank
    Student bob = ht.search("Bob");
    Student frank = ht.search("Frank");

    //Print Bob and Frank
    cout << "Bob" << endl;
    bob.print();
    cout << endl;
    cout << "Frank" << endl;
    frank.print();
    cout << endl;

    //Compare Bob and Frank
    StudentNameComparator nameComparator;
    StudentIdComparator idComparator;

    cout << "Name : Bob < Frank: " << nameComparator(bob, frank) << endl;
    cout << "ID: Bob < Frank: " << idComparator(bob, frank) << endl;


    

    return 0;
}