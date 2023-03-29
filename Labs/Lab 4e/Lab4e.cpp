//Andrew Card

#include <iostream>
#include <list>
#include <string>

using namespace std;

bool isEmailValid(string email){
    list<string> validEmailExtensions =  { "@gmail.com", "@aol.com", "@cos.edu", "@giant.cos.edu"};

    //Despace the input string
    email.erase(remove(email.begin(), email.end(), ' '), email.end());

    //Find the @
    int atLocation = email.find('@');

    //If there is no @, return false
    if(atLocation == string::npos){
        //Throw exception
        throw invalid_argument("Email does not contain an @");
    }

    //Check if the extension is valid
    for(string extension : validEmailExtensions){
        if(email.substr(atLocation) == extension){
            return true;
        }
    }

    return false;

}

int main(){

    //Clear the screen
    system("cls");

    //Get email from user
    string email;
    cout << "Enter an email address: ";
    getline(cin, email);

    //Loop
    while(email != ""){
        try{
            //Check if email is valid
            if(isEmailValid(email)){
                cout << "Email is valid" << endl;
            }else{
                cout << "Email is invalid" << endl;
            }
        }catch(invalid_argument e){
            cout << e.what() << endl;
        }

        //Get email from user
        cout << "Enter an email address: ";
        getline(cin, email);
    }


    return 0;
}