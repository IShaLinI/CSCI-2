//Andrew Card

#include <iostream>
#include <string>

using namespace std;

int stringToIndexHash(string userName, int buckets){
    int sum = 0;
    for(int i = 0; i < userName.length(); i++){
        sum += userName[i];
    }
    return sum % buckets;
}

string lowercase(string input){
    string output = "";
    for(int i = 0; i < input.length(); i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            output += input[i] + 32;
        }else{
            output += input[i];
        }
    }
    return output;
}

int main(){

    //Get user string input.
    string input;
    cout << "Enter a string: ";
    getline(cin,input);

    //Get number of buckets.
    int buckets;
    cout << "Enter the number of buckets: ";
    cin >> buckets;

    //Convert to lowercase
    input = lowercase(input);

    //Hash the string
    int index = stringToIndexHash(input, buckets);

    //Output the index
    cout << "Index: " << index << endl;

    return 0;
}