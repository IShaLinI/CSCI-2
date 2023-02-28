// Notes: Singly Linked List 
// An abstraction of an array.

#include <iostream> 
#include <string>
using namespace std;

// Class that defines the node object
class Node {
private:
    string item;
    Node* nextPtr;

public:
    //constructors
    Node();
    Node(string);
    Node(string, Node*);

    //Accessor Methods
    void setItem(string);
    string getItem();
    void setNextPtr(Node*);
    Node* getNextPtr();

};

//regular c-type function for printing the Linked List
void printStringList(Node* beginningNodePtr);

int main(void) {

    srand(time(NULL));

    Node* headPtr = nullptr;

    for(int i = 0; i < 100; i++){
        char c = rand() % 26 + 97;
        Node* newNodePtr = new Node(string(1, c));
        newNodePtr->setNextPtr(headPtr);
        headPtr = newNodePtr;
    }

    printStringList(headPtr);

    //delete the list
    Node* tempNodePtr = headPtr;
    while (tempNodePtr != nullptr) {
        Node* nextNodePtr = tempNodePtr->getNextPtr();
        delete tempNodePtr;
        tempNodePtr = nextNodePtr;
    }

    return (0);
}

void printStringList(Node* beginningNodePtr) {

    Node* tempNodePtr = beginningNodePtr;

    cout << "******************" << endl;
    if (tempNodePtr == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        while (tempNodePtr->getNextPtr() != nullptr) {

            cout << tempNodePtr->getItem() << endl;
            tempNodePtr = tempNodePtr->getNextPtr();

        };
        cout << tempNodePtr->getItem() << endl;

    }
    cout << "******************" << endl;

}


//Node Implementation
Node::Node()
{
    setItem(""); //default to empty string
    setNextPtr(nullptr); //default to null pointer
}

Node::Node(string arg)
{
    setItem(arg);
    setNextPtr(nullptr);
}

Node::Node(string arg, Node* argPtr)
{
    setItem(arg);
    setNextPtr(argPtr);
}

void Node::setItem(string arg)
{
    item = arg;
}

string Node::getItem()
{
    return item;
}

void Node::setNextPtr(Node* argPtr)
{
    nextPtr = argPtr;
}

Node* Node::getNextPtr()
{
    return nextPtr;
}