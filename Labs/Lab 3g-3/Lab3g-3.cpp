//Andrew Card

#include <iostream>
#include <stdlib.h>

using namespace std;

//Templatized Double Linked Node
template <class T>
class Node {
    public:
        Node(T*t) {
            data = t;
            next = NULL;
            prev = NULL;
        }
        
        Node(T t){
            data = new T(t);
            next = NULL;
            prev = NULL;
        }

        T* data;
        Node* next;
        Node* prev;
};

//Templatized Double Linked List
template <class T>
class List {
    public:

        //Constuctor
        List() {
            head = NULL;
            tail = NULL;
        }

        //Destructor
        ~List() {
            Node<T>* current = head;
            while (current != NULL) {
                Node<T>* temp = current;
                current = current->next;
                delete temp;
            }
        }

        void pushBack(T* t) {
            Node<T>* newNode = new Node<T>(t);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void popBack() {
            if (head == NULL) {
                return;
            }
            else if (head == tail) {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else {
                Node<T>* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                delete tail;
                tail = current;
                tail->next = NULL;
            }
        }

        void insertAfter(T* t1, T* t2) {
            Node<T>* newNode = new Node<T>(t2);
            Node<T>* current = head;
            while (current != NULL) {
                if (current->data == t1) {
                    newNode->next = current->next;
                    newNode->prev = current;
                    current->next = newNode;
                    if (newNode->next != NULL) {
                        newNode->next->prev = newNode;
                    }
                    else {
                        tail = newNode;
                    }
                    return;
                }
                current = current->next;
            }
        }

        void deleteNode(T* t){
            Node<T>* current = head;
            while (current != NULL) {
                if (current->data == t) {
                    if (current->prev != NULL) {
                        current->prev->next = current->next;
                    }
                    else {
                        head = current->next;
                    }
                    if (current->next != NULL) {
                        current->next->prev = current->prev;
                    }
                    else {
                        tail = current->prev;
                    }
                    delete current;
                    return;
                }
                current = current->next;
            }
        }

        void print() {
            Node<T>* current = head;
            while (current != NULL) {
                cout << *current->data << endl; 
                current = current->next;
            }
        }

        int size(){
            int count = 0;
            Node<T>* current = head;
            while (current != NULL) {
                count++;
                current = current->next;
            }
            return count;
        }

        Node<T>* head;
        Node<T>* tail;
};


int main(){

    //Clear the screen
    system("CLS");

    //Seed the random number generator
    srand(time(NULL));

    //Create a list of strings
    List<string> stringList;

    //Random Word bank
    string wordBank[10] = {"Andrew", "Card", "C++", "Programming", "Lab", "List", "Node", "Double", "Linked", "List"};

    //Add words to the list in a random order
    for (int i = 0; i < 10; i++) {
        stringList.pushBack(new string(wordBank[rand() % 10]));
    }

    //Print the list
    stringList.print();

    cout << "\nDeleting the last node" << endl;
    //Remove the last node
    stringList.popBack();

    //Print the list
    stringList.print();

    int nodeToInsertAfter = rand() % stringList.size();
    cout << "\nInserting a new node after node " << nodeToInsertAfter << endl;

    //Insert a new node after a random node
    Node<string>* current = stringList.head;
    for (int i = 0; i < nodeToInsertAfter; i++) {
        current = current->next;
    }
    stringList.insertAfter(current->data, new string("New Node"));

    //Print the list
    stringList.print();

    //Delete a random node
    int nodeToDelete = rand() % stringList.size();
    cout << "\nDeleting node " << nodeToDelete << endl;
    current = stringList.head;
    for (int i = 0; i < nodeToDelete; i++) {
        current = current->next;
    }
    stringList.deleteNode(current->data);

    //Print the list
    stringList.print();
    
    //Show the size of the list
    cout << "\nSize of the list: " << stringList.size() << endl;
    
    return 0;
}