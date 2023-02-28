//Andrew Card

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Templated node
template <typename T>
class Node {
    public:
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
        T getData(){
            return data;
        };
        Node* getNext(){
            return next;
        };
        void setData(T d){
            data = d;
        };
        void setNext(Node* n) {
            next = n;
        };
    private:
        T data;
        Node* next;
};

template <typename T>
void printList(Node<T>* head){
    Node<T>* current = head;
    while(current != NULL){
        cout << current->getData() << endl;
        current = current->getNext();
    }
}

template <typename T>
void printListReverse(Node<T>* head){

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

template <typename T>
int getListLength(Node<T>* head){
    int length = 0;
    Node<T>* current = head;
    while(current != NULL){
        length++;
        current = current->getNext();
    }
    return length;
}

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
    Node<int>* head1 = new Node<int>(0);
    Node<int>* current = head1;
    for(int i = 1; i < 5; i += 1){
        current->setNext(new Node<int>(i));
        current = current->getNext();
    }
    cout << "List 1:" << endl;
    printList(head1);
    
    Node<int>* head2 = new Node<int>(5);
    current = head2;
    for(int i = 6; i < 10; i += 1){
        current->setNext(new Node<int>(i));
        current = current->getNext();
    }

    cout << "List 2:" << endl;
    printList(head2);

    Node<int>* merged = mergeLists(head1, head2);
    cout << "Merged List:" << endl;
    printList(merged);


    return 0;
}