//Andrew Card

#include <iostream>
#include <map>

using namespace std;

class User {
    private:
        string username;
        string password;
        string email;
    public:
        User(string username, string password, string email){
            this->username = username;
            this->password = password;
            this->email = email;
        }

        string getUsername(){
            return username;
        }

        string getPassword(){
            return password;
        }

        string getEmail(){
            return email;
        }
};

enum menuOptions{
    LANDING,
    LOGIN,
    REGISTER,
    DATABASE_SORT_OPTIONS,
    DATABASE_A_Z_SELECT,
    DATABASE_HIST
};

//Validate login username
bool validateLoginUsername(string username, map<int, User>* userMap){

    //Check for spaces
    if(username.find(' ') != string::npos){
        throw invalid_argument("Username cannot contain spaces");
    }

    //Check if user is in the database
    if(!checkUsernameExists(username, *userMap)){
        throw invalid_argument("Username not in database");
    }

    return true;

}

//Validate login password
bool validateLoginPassword(string password, map<int, User>* userMap){

    //Check for spaces
    if(password.find(' ') != string::npos){
        throw invalid_argument("Password cannot contain spaces");
    }

    return true;
}

//Verify login attemp
bool loginAttempt(string username, string password, map<int, User>* userMap){
    for(pair<int, User> user : *userMap){
        if(user.second.getUsername() == username && user.second.getPassword() == password){
            return true;
        }
    }
    return false;
}

bool checkUsernameExists(string username, map<int, User> userMap){
    for(pair<int, User> user : userMap){
        if(user.second.getUsername() == username){
            return true;
        }
    }
    return false;
}

void showLoginPage(){
    system("cls");
    cout << "=======================" << endl;
    cout << "         Login         " << endl;
    cout << "=======================" << endl;

    cout << "Enter your username: ";

}

int main(){

    menuOptions currentMenu = LANDING;

    showLandingPage();

    //User map
    map<int, User> userMap;

    return 0;
}