//Andrew Card

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Creates a node class to store data of any single type
template <typename T>
class Node {
    public:
        //Constructors for feeding some or no data
        Node(){
            data = T();
            next = nullptr;
        };
        Node(T d){
            data = d;
            next = nullptr;
        };
        Node(T d, Node* n){
            data = d;
            next = n;
        };

        //Method for grabbing a datapoint
        T getData(){
            return data;
        };

        //Method for grabbing the next data node
        Node* getNext(){
            return next;
        };

        //Method fors setting date of a node
        void setData(T d){
            data = d;
        };

        //Method of settingt the address of the next node
        void setNext(Node* n) {
            next = n;
        };
    private:
        //Node variable
        T data;
        Node* next;
};

//Print a node of any type
template <typename T>
void printList(Node<T>* head){
    Node<T>* current = head;
    //Linked lists end somewhere so detect when you hit it
    while(current != NULL){
        cout << current->getData() << endl;
        current = current->getNext();
    }
}

//Prints a node reversed
template <typename T>
void printListReverse(Node<T>* head){

    //The node structure doesnt go both ways so i just temp store in a vector
    vector<T> data;

    Node<T>* current = head;
    while(current != NULL){
        data.push_back(current->getData());
        current = current->getNext();
    }

    for(int i = data.size() - 1; i >= 0; i--){
        cout << data[i] << endl;
    }

}

//Grabs the length of a linked list of any type
template <typename T>
int getListLength(Node<T>* head){
    //accum variable
    int length = 0;
    Node<T>* current = head;
    while(current != NULL){
        length++;
        current = current->getNext();
    }
    return length;
}

//Merge 2 Linked lists together.
template <typename T>
Node<T>* mergeLists(Node<T>* head1, Node<T>* head2){
    Node<T>* current1 = head1;
    Node<T>* current2 = head2;
    Node<T>* newHead = NULL;
    Node<T>* newCurrent = NULL;
    Node<T>* temp = NULL;

    while(current1 != NULL && current2 != NULL){
        if(current1->getData() < current2->getData()){
            if(newHead == NULL){
                newHead = current1;
                newCurrent = current1;
            } else {
                newCurrent->setNext(current1);
                newCurrent = newCurrent->getNext();
            }
            current1 = current1->getNext();
        } else {
            if(newHead == NULL){
                newHead = current2;
                newCurrent = current2;
            } else {
                newCurrent->setNext(current2);
                newCurrent = newCurrent->getNext();
            }
            current2 = current2->getNext();
        }
    }

    if(current1 != NULL){
        newCurrent->setNext(current1);
    } else if(current2 != NULL){
        newCurrent->setNext(current2);
    }

    return newHead;
}

int main(){
    //Define a list with a starter node at 0
    Node<int>* head1 = new Node<int>(0);
    //Store the currently sook address
    Node<int>* current = head1;

    for(int i = 1; i < 5; i += 1){
        //Loop through adding new nodes to the list
        current->setNext(new Node<int>(i));
        current = current->getNext();
    }

    //Label and print the list
    cout << "List 1:" << endl;
    printList(head1);
    
    //Define a list with a starter node of 5
    Node<int>* head2 = new Node<int>(5);
    current = head2;
    for(int i = 6; i < 10; i += 1){
        current->setNext(new Node<int>(i));
        current = current->getNext();
    }

    //Label and print the list
    cout << "List 2:" << endl;
    printList(head2);

    //Create an new list from the two previous ones
    Node<int>* merged = mergeLists(head1, head2);
    
    //Label and print the list
    cout << "Merged List:" << endl;
    printList(merged);

    return 0;
}