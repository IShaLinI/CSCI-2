// Andrew Card

#include <iostream>

using namespace std;

class Person
{

    string firstName;
    string lastName;
    int age;

public:
    Person(string _FirstName, string _LastName, int _Age);
    string getFirstName();
    string getLastName();
    int getAge();
    void print();
};

class UScitizen
{
private:
    Person person;
    int ssn;

public:
    UScitizen(Person _Person, int _SSN);
    Person getPerson();
    void print();
};

int main()
{

    Person person1("Henry", "Johnson", 45);
    Person person2("John", "Henry", 12);
    Person person3("Steve", "Works", 40);

    UScitizen citizen1(person1, 73);
    UScitizen citizen2(person2, 60);
    UScitizen citizen3(person3, 110);

    citizen1.print();
    cout << endl;
    citizen2.print();
    cout << endl;
    citizen3.print();
    cout << endl;

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

UScitizen::UScitizen(Person _Person, int _SSN)
{
    person = _Person;
    ssn = _SSN;
}

Person UScitizen::getPerson()
{
    return person;
}

void UScitizen::print()
{
    person.print();
    cout << "SSN: " << ssn << endl;
}