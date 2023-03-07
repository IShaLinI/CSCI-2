//Andrew Card

#include <iostream>
#include <list>
#include <stdlib.h>

using namespace std;

//Person Class
class Person
{
public:
    Person(string _FirstName, string _LastName, int _Age){
        firstName = _FirstName;
        lastName = _LastName;
        age = _Age;
    }
    string getFirstName(){
        return firstName;
    }
    string getLastName(){
        return lastName;
    }
    int getAge(){
        return age;
    }
    void print(){
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Age: " << age << endl;
    }
    string firstName;
    string lastName;
    int age;
};

//UScitizen Class
class UScitizen : public Person
{
public:
    int ssn;
    UScitizen(string _FirstName, string _LastName, int _Age, int _SSN) : Person(_FirstName, _LastName, _Age){
        firstName = _FirstName;
        lastName = _LastName;
        age = _Age;
        ssn = _SSN;
    }
    void print(){
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Age: " << age << endl;
    }
};

//Employee Class
class Employee : public UScitizen {
    int employeeID;
    double salary;
public:
    Employee(string _FirstName, string _LastName, int _Age, int _SSN, int _EmployeeID, double _Salary) : UScitizen(_FirstName, _LastName, _Age, _SSN){
        firstName = _FirstName;
        lastName = _LastName;
        age = _Age;
        ssn = _SSN;
        employeeID = _EmployeeID;
        salary = _Salary;
    }
    void print(){
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Age: " << age << endl;
        cout << "SSN: " << ssn << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main(){

    system("CLS");

    srand(time(NULL));

    //First name bank
    string firstNames[10] = {"Andrew", "Bob", "Cindy", "Derek", "Ethan", "Frank", "George", "Hannah", "Ivan", "Jenny"};
    //Last name bank
    string lastNames[10] = {"Card", "Doe", "Smith", "Jones", "Johnson", "Williams", "Brown", "Davis", "Miller", "Wilson"};

    //List of employees
    list<Employee> employees;

    //Add 300 Random Employees
    for(int i = 0; i < 300; i++){

        //Randomize first name
        int firstNameIndex = rand() % 10;
        string firstName = firstNames[firstNameIndex];

        //Randomize last name
        int lastNameIndex = rand() % 10;
        string lastName = lastNames[lastNameIndex];

        //Randomize age
        int age = rand() % 100;

        //Randomize SSN
        int ssn = rand() % 1000000000;

        //Randomize Employee ID
        int employeeID = rand() % 1000000000;

        //Randomize Salary
        double salary = rand() % 100000;

        //Create Employee
        Employee employee(firstName, lastName, age, ssn, employeeID, salary);

        //Add Employee to list
        employees.push_back(employee);

    }

    //Print all employees
    for(list<Employee>::iterator i = employees.begin(); i != employees.end(); i++){
        i->print();
        cout << endl;
    }

    //Count employees
    cout << employees.size() << " Employees before" << endl;

    //Clear the list
    cout << "Clearing list..." << endl;
    employees.clear();

    //Count employees
    cout << employees.size() << " Employees after" << endl;
    

    return 0;
}