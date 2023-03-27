//Andrew Card

#include <iostream>
#include <stack>
#include <string>

using namespace std;

//Check for palindromes in a stack of chars
bool isPalindrome(stack<char> myStack){

    //Create a copy of input stack
    stack<char> myStack1 = myStack;

    //Create a second stack
    stack<char> myStack2;

    //Reverse the first stack
    while(!myStack1.empty()){
        myStack2.push(myStack1.top());
        myStack1.pop();
    }

    //Check if the two stacks are equal
    while(!myStack2.empty()){
        if(myStack2.top() != myStack.top()){
            return false;
        }
        myStack2.pop();
        myStack.pop();
    }

    return true;
}

bool panisPalindrome(stack<char> chars) {
    stack<char> forward = chars;
    stack<char> backward;

    while (!chars.empty()) {
        backward.push(chars.top());
        chars.pop();
    }

    while (!forward.empty()) {
        if (backward.top() == forward.top()) {
            backward.pop();
            forward.pop();
        }
        else {
            return false;
        }
    }

    return true;
}


int main(){

    system("CLS");

    //Get user string
    string userString;
    cout << "Enter a string: ";
    getline(cin, userString);

    //Create a stack for chars
    stack<char> myStack;

    //Push the string into the stacck
    for(int i = 0; i < userString.length(); i++){
        myStack.push(userString[i]);
    }

    //Check if the stack is a palindrome
    if(panisPalindrome(myStack)){
        cout << "The string is a palindrome" << endl;
    }else{
        cout << "The string is not a palindrome" << endl;
    }

    return 0;
}