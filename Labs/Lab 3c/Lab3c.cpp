//Andrew Card

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Templated node
template <class T>
class Node {
public:
    Node() {
        data = T();
        next = nullptr;
    };
    Node(T d) {
        data = d;
        next = nullptr;
    };
    Node(T d, Node* n) {
        data = d;
        next = n;
    };
    T getData() {
        return data;
    };
    Node* getNext() {
        return next;
    };
    void setData(T d) {
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
void printList(Node<T>* head) {
    Node<T>* current = head;
    while (current != NULL) {
        cout << current->getData() << endl;
        current = current->getNext();
    }
}

template <typename T>
void printListReverse(Node<T>* head) {

    vector<T> data;

    Node<T>* current = head;
    while (current != NULL) {
        data.push_back(current->getData());
        current = current->getNext();
    }

    for (int i = data.size() - 1; i >= 0; i--) {
        cout << data[i] << endl;
    }

}

template <typename T>
int getListLength(Node<T>* head) {
    int length = 0;
    Node<T>* current = head;
    while (current != NULL) {
        length++;
        current = current->getNext();
    }
    return length;
}

int main() {

    bool first = true;

    //Create a linked list of strings
    Node<string>* head = new Node<string>();
    Node<string>* current = head;

    while (true) {
        cout << "Enter a string to add to the list:";
        string input;
        getline(cin, input);
        if (first) {
            head->setData(input);
            first = false;
        }
        else {
            current->setNext(new Node<string>(input));
            current = current->getNext();
        }
        cout << "Continue? (y/n): ";
        cin >> input;
        if (input == "n") {
            break;
        }
        cin.ignore();
    }

    cout << "List length: " << getListLength(head) << endl;
    cout << "List contents:" << endl;
    printList(head);
    cout << "List contents in reverse:" << endl;
    printListReverse(head);

    return 0;
}