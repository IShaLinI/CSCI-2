public:
    Person(){throw invalid_argument("No data passed to person");}
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
        cout << "Name: " << lastName << " " << firstName << endl;
        cout << "Age: " << age << endl;
    }
