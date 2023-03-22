//Andrew Card

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    //Create a stack for strings
    stack<string> myStack;

    //Put user strings into a stack
    string userString;
    cout << "Enter a string: ";

    getline(cin, userString);

    while(userString != ""){
        myStack.push(userString);
        cout << "Enter a string: ";
        getline(cin, userString);
    }

    //Print the stack
    while(!myStack.empty()){
        cout << myStack.top() << endl;
        myStack.pop();
    }

    //Check if the stack is empty
    if(myStack.empty()){
        cout << "The stack is empty" << endl;
    }

    return 0;
}