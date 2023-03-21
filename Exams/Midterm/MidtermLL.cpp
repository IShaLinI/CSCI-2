//Andrew Card

#include <iostream>

using namespace std;

template<class T>
class Node {
    public:
        T obj;
        Node* next;
        Node* prev;
};

//Print Forward
template<typename T>
void printForward(Node<T>* head);

//Print Reverse
template<typename T>
void printReverse(Node<T>* head);

//get the length of the list
template<typename T>
int length(Node<T>* head);

//Delete 2nd Node
template<typename T>
void delete2nd(Node<T>* head);

int main(){

    //List of 3 strings
    Node<string>* head = new Node<string>;

    head->obj = "C++";
    head->next = new Node<string>;
    head->prev = nullptr;

    head->next->obj = "Data";
    head->next->prev = head;
    head->next->next = new Node<string>;

    head->next->next->obj = "Structure";
    head->next->next->prev = head->next;
    head->next->next->next = nullptr;

    //Print the list forward
    printForward(head);

    cout << endl;

    //Print the list backward
    printReverse(head);

    cout << endl;

    //Print the length of the list
    cout << "Length: " << length(head) << endl;

    cout << endl;

    //Delete the 2nd node
    delete2nd(head);

    //Print the list forward
    printForward(head);

    cout << endl;

    //Print the list backward
    printReverse(head);

    cout << endl;

    //Print the length of the list
    cout << "Length: " << length(head) << endl;


    return 0;
}

//Print Forward
template<typename T>
void printForward(Node<T>* head) {
    Node<T>* cur = head;
    if (cur == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        do {
            cout << cur->obj << endl;
            cur = cur->next;
        } while (cur != nullptr);
    }

}

//Print Reverse
template<typename T>
void printReverse(Node<T>* head) {
    Node<T>* cur = head;
    if (cur == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        //iterate to end;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cout << cur->obj << endl;
        while (cur->prev != nullptr) {
            cur = cur->prev;
            cout << cur->obj << endl;
        }
    }
}

//get the length of the list
template<typename T>
int length(Node<T>* head) {
    Node<T>* cur = head;
    int count = 0;
    if (cur == nullptr) {
        return 0;
    }
    else {
        do {
            count++;
            cur = cur->next;
        } while (cur != nullptr);
    }
    return count;
}

//Delete 2nd Node
template<typename T>
void delete2nd(Node<T>* head) {
    Node<T>* cur = head;
    if (cur == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        if (cur->next == nullptr) {
            cout << "List only has 1 element" << endl;
        }
        else {
            cur = cur->next;
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
        }
    }
}