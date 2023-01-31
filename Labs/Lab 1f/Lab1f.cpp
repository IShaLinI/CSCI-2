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
private:
    int ssn;
public:
    UScitizen(string _FirstName, string _LastName, int _Age, int _SSN);
    void print();
};

int main()
{

    Person person1("Henry", "Johnson", 45);
    Person person2("John", "Henry", 12);

    UScitizen citizen1("King", "James", 457, 5);
    UScitizen citizen2("Queen", "Victoria", 122, 15);
    UScitizen citizen3("Brian", "Oleary", 20, 770);

    person1.print();
    person2.print();
    cout << endl;
    citizen1.print();
    citizen2.print();
    citizen3.print();

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