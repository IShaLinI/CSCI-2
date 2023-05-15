//Andrew Card

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

//Person class
class Person{
    private:
        string name;
        int age;
        string gender;
    public:
        Person(string _name, int _age, string _gender){
            name = _name;
            age = _age;
            gender = _gender;
        }

        Person(vector<string> data){
            name = data[0];
            age = stoi(data[1]);
            gender = data[2];
        }

        string getCSVEntry(){
            return name + "," + to_string(age) + "," + gender + "\n";
        }

        string getName(){
            return name;
        }

        int getAge(){
            return age;
        }

        string getGender(){
            return gender;
        }

};

class CSVFile {
    private:
        string fileName;
        string filePath;
        list<Person> people;

        void load(){

            people.clear();

            //Open the file
            ifstream file (filePath + fileName);
            stringstream iss;
            iss << file.rdbuf();

            //Check if the file is open
            if(file.is_open()){
                for(string line; getline(iss, line);){

                    //Split line into 3 strings
                    vector<string> data;
                    stringstream ss(line);
                    for(string s; ss.good();){
                        getline(ss, s, ',');
                        data.push_back(s);
                    }

                    //Create a person object and add it to the list
                    Person p(data);
                    people.push_back(p);
                }
            }
        }

    public:
        CSVFile(string _fileName){
            filePath = "";
            fileName = _fileName;
            load();
        }

        CSVFile(string _filePath, string _fileName){
            filePath = _filePath;
            fileName = _fileName;
            load();
        }

        void addEntry(Person p){
            people.push_back(p);
            sort();
        }

        void clearFile(){

            //Delete the file
            remove((filePath + fileName).c_str());
            
            //Clear the program memory
            people.clear();

        }

        void save(){
            ofstream file(filePath + fileName);
            if(file.is_open()){
                for(Person p : people){
                    file << p.getCSVEntry();
                }
            }
        }

        void display(){
            for(Person p : people){
                cout << "Name: " << p.getName() << endl;
                cout << "Age: " << p.getAge() << endl;
                cout << "Gender: " << p.getGender() << endl << endl;
            }
        }

        void sort(){
            //Sort the list of people by age
            people.sort([](Person &a, Person &b){
                return a.getAge() < b.getAge();
            });
        }
};

int main(){

    system("CLS");

    CSVFile file("people.csv");

    file.clearFile();

    while(true){

        system("CLS");

        string inputName;
        int inputAge;
        string inputGender;

        cout << "Enter a name: ";
        cin >> inputName;
        cout << "Enter an age: ";
        cin >> inputAge;
        cout << "Enter a gender: ";
        cin >> inputGender;

        Person p(inputName, inputAge, inputGender);

        file.addEntry(p);

        cout << "Would you like to add another person? (y/n): ";

        string input;
        cin >> input;

        if(input == "n"){
            break;
        }        

    }

    system("CLS");

    //Save the file
    file.save();

    //Display the file
    file.display();

    return 0;
}