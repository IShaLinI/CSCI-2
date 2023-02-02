// Andrew Card

#include <iostream>

using namespace std;

class Person
{

public:
    Person(string _FirstName, string _LastName, int _Age);
    string getFirstName();
    string getLastName();
    int getAge();
    virtual void print();

    string firstName;
    string lastName;
    int age;
};

class UScitizen : public Person
{ 
public:
    int ssn;
    UScitizen(string _FirstName, string _LastName, int _Age, int _SSN);
    void print();
};

class Employee : public UScitizen {

private:
    int employeeID;
    double salary;
public:
    Employee(string _FirstName, string _LastName, int _Age, int _SSN, int _EmployeeID, double _Salary);
    void print();

};


int main()
{

    Employee employee1("Henry", "Johnson", 45, 123, 1, 1000.40);
    Employee employee2("John", "Henry", 12, 456, 2, 2000.10);

    employee1.print();
    employee2.print();

    return 0;
}

Person::Person(string _FirstName = "", string _LastName = "", int _Age = -1)
{
    firstName = _FirstName;
    lastName = _LastName;
    age = _Age;
}

string Person::getFirstName()
{
    return firstName;
}

string Person::getLastName()
{
    return lastName;
}

int Person::getAge()
{
    return age;
}

void Person::print()
{
    cout << "Name: " << lastName << " " << firstName << endl;
    cout << "Age: " << age << endl;
}

UScitizen::UScitizen(string _FirstName, string _LastName, int _Age, int _SSN) : Person(_FirstName, _LastName, _Age){
    ssn = _SSN;
}

void UScitizen::print()
{
    cout << "Name: " << lastName << " " << firstName << endl;
    cout << "Age: " << age << endl;
    cout << "SSN: " << ssn << endl;
}

Employee::Employee(string _FirstName, string _LastName, int _Age, int _SSN, int _EmployeeID, double _Salary) : UScitizen(_FirstName, _LastName, _Age, _SSN)
{
    employeeID = _EmployeeID;
    salary = _Salary;
}

void Employee::print()
{
    cout << "Name: " << lastName << " " << firstName << endl;
    cout << "Age: " << age << endl;
    cout << "SSN: " << ssn << endl;
    cout << "Employee ID: " << employeeID << endl;
    cout << "Salary: " << salary << endl;
}