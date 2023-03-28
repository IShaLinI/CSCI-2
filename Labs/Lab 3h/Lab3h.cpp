//Andrew Card

#include <iostream>
#include <list>

using namespace std;

//Person class
class Person {
    public:
        Person(string n, int a) {
            name = n;
            age = a;
        }

        virtual void display(){
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }

        string name;
        int age;
};

//Student class that inherits from Person
class Student : public Person {
    public:
        Student(string n, int a, int g) : Person(n, a) {
            gpa = g;
        }

        virtual void display(){
            Person::display();
            cout << "GPA: " << gpa << endl;
        }

        int gpa;
};

//Staff class that inherits from Person
class Staff : public Person {
    public:
        Staff(string n, int a, string t) : Person(n, a) {
            title = t;
        }

        void display(){
            Person::display();
            cout << "Title: " << title << endl;
        }

        string title;
};

//Athlete class that inherits from Student
class Athlete : public Student {
    public:
        Athlete(string n, int a, int g, string s) : Student(n, a, g) {
            sport = s;
        }

        void display(){
            Student::display();
            cout << "Sport: " << sport << endl;
        }

        string sport;
};

int main(){

    system("CLS");

    Person* testPerson = new Person("Kevin", 20);

    Student* testStudent = new Student("Carol", 17, 3.5);

    Staff* testStaff = new Staff("Bob", 30, "Janitor");

    Athlete* testAthlete = new Athlete("James", 18, 4.0, "Basketball");

    //List of base classes
    list<Person*> people;

    //Add objects to list
    people.push_back(testPerson);
    people.push_back(testStudent);
    people.push_back(testStaff);
    people.push_back(testAthlete);

    //Show all people
    for (list<Person*>::iterator it = people.begin(); it != people.end(); it++){
        (*it)->display();
        cout << endl;
    }
    
    //Clean up the objects
    delete testPerson;
    delete testStudent;
    delete testStaff;
    delete testAthlete;

    return 0;
}