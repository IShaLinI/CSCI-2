//Andrew Card

#include <iostream>
#include <map>
#include <string>

using namespace std;

//Student class
class Student{
public:
    Student(){
        firstName = "";
        id = 0;
        age = 0;
        gpa = 0;
    }
    Student(string _FirstName, int _id, int _Age, double _GPA){
        firstName = _FirstName;
        id = _id;
        age = _Age;
        gpa = _GPA;
    }
    string getFirstName(){
        return firstName;
    }
    int getID(){
        return id;
    }
    int getAge(){
        return age;
    }
    double getGPA(){
        return gpa;
    }
    void print(){
        cout << "Name: " << firstName << endl;
        cout << "ID: " << id << endl;
        cout << "Age: " << age << endl;
        cout << "GPA: " << gpa << endl;
    }
    string firstName;
    int id;
    int age;
    double gpa;
};

int main(){

    system("CLS");

    //Map of 5 students
    map<string, Student> students;

    //Add 5 students to map
    students["andrew@cos.edu"] = Student("Andrew", 101201231, 20, 3.5);
    students["bob@cos.edu"] = Student("Bob", 101201254, 21, 3.4);
    students["cameron@cos.edu"] = Student("Cameron", 101301231, 22, 3.3);
    students["david@cos.edu"] = Student("David", 101206431, 23, 3.2);
    students["edward@cos.edu"] = Student("Edward", 101292231, 24, 3.1);

    //Allow user to search for student

    string email = " ";

    while(true){
        cout << "Enter email: ";
        getline(cin,email);

        //Get student information
        if(students.find(email) != students.end()){
            students[email].print();
        }
        if(email == ""){
            break;
        }
        else{
            cout << "Student not found" << endl;
        }

    }

    cout << "Program Finished";

    return 0;
}