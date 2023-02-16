//Andrew Card

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
    public:
        Node(){
            string = "";
            next = nullptr;
        };
        Node(string s){
            string = s;
            next = nullptr;
        };
        Node(string s, Node* n){
            string = s;
            next = n;
        };
        string getString(){
            return string;
        };
        Node* getNext(){
            return next;
        };
        void setString(string s){
            string = s;
        };
        void setNext(Node* n) {
            next = n;
        };
    private:
        string string;
        Node* next;
};

void printList(Node* head){
    Node* current = head;
    while(current != NULL){
        cout << current->getString() << endl;
        current = current->getNext();
    }
}

void printListReverse(Node* head){

    vector<string> strings;

    Node* current = head;
    while(current != NULL){
        strings.push_back(current->getString());
        current = current->getNext();
    }

    for(int i = strings.size() - 1; i >= 0; i--){
        cout << strings[i] << endl;
    }

}

int getListLength(Node* head){
    int length = 0;
    Node* current = head;
    while(current != NULL){
        length++;
        current = current->getNext();
    }
    return length;
}

int main(){

    bool first = true;

    Node* head = new Node();
    Node* current = head;

    while(true){
        cout << "Enter a string to add to the list:";
        string input;
        getline(cin, input);
        if(first){
            head->setString(input);
            first = false;
        } else {
            current->setNext(new Node(input));
            current = current->getNext();
        }
        cout << "Continue? (y/n): ";
        cin >> input;
        if(input == "n"){
            break;
        }
        cin.ignore();
    }

    cout << "Your List: " << endl;
    printList(head);

    cout << "Your List in reverse: " << endl;
    printListReverse(head);

    cout << "Your List length: ";
    cout << getListLength(head) << endl;

    return 0;
}