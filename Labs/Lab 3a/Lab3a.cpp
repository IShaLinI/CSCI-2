//Andrew Card

#include <iostream>

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
        void setString(string){
            string = string;
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

int main(){

    Node* head = new Node("Hello");
    Node* current = head;

    current->setNext(new Node("Linked"));
    current = current->getNext();
    
    current->setNext(new Node("Lists"));
    current = current->getNext();


    cout << "Printing List: " << endl;
    printList(head);

    return 0;
}