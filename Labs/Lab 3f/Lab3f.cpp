//Andrew Card

#include <iostream>

using namespace std;

//double linked list
template <typename T>
class Node {
    public:
        //Constructors for feeding some or no data
        Node(){
            data = T();
            next = nullptr;
            prev = nullptr;
        };
        Node(T d){
            data = d;
            next = nullptr;
            prev = nullptr;
        };
        Node(T d, Node* n, Node* p){
            data = d;
            next = n;
            prev = p;
        };

        //Method for grabbing a datapoint
        T getData(){
            return data;
        };

        //Method for grabbing the next data node
        Node* getNext(){
            return next;
        };

        //Method for grabbing the previous data node
        Node* getPrev(){
            return prev;
        }

        //Method fors setting date of a node
        void setData(T d){
            data = d;
        };

        //Method of settingt the address of the next node
        void setNext(Node* n) {
            next = n;
        };

        //Method of settingt the address of the previous node
        void setPrev(Node* p) {
            prev = p;
        };

        //Get the last node
        Node* getLast(){
            Node* current = this;
            while(current->getNext() != NULL){
                current = current->getNext();
            }
            return current;
        }

        //Get the first node
        Node* getFirst(){
            Node* current = this;
            while(current->getPrev() != NULL){
                current = current->getPrev();
            }
            return current;
        }

        //Add a node to the end of the list
        void pushBack(T d){
            Node* last = getLast();
            Node* newNode = new Node(d);
            last->setNext(newNode);
            newNode->setPrev(last);
        }

        //Add a node to the start of the list
        void pushFront(T d){
            Node* newNode = new Node(d);
            newNode->setNext(this);
            this->setPrev(newNode);
        }

        //Delete last node
        void popBack(){
            Node* last = getLast();
            Node* secondLast = last->getPrev();
            secondLast->setNext(NULL);
            delete last;
        }

        //Print the entire list
        void printList(){
            Node* current = getFirst();
            while(current != NULL){
                cout << current->getData() << endl;
                current = current->getNext();
            }
        }

        //Print the entire list in reverse
        void printListReverse(){
            Node* current = getLast();
            while(current != NULL){
                cout << current->getData() << endl;
                current = current->getPrev();
            }
        }

        //Insert a node at a given node
        void insertAfter(Node* n, T d){
            Node* newNode = new Node(d);
            Node* nextNode = n->getNext();
            n->setNext(newNode);
            newNode->setPrev(n);
            newNode->setNext(nextNode);
            nextNode->setPrev(newNode);
        }

        //Deallocate the entire list
        void deleteList(){
            Node* current = getFirst();
            while(current != NULL){
                Node* next = current->getNext();
                delete current;
                current = next;
            }
        }

        //Search for data
        Node* search(T d){
            Node* current = getFirst();
            while(current != NULL){
                if(current->getData() == d){
                    return current;
                }
                current = current->getNext();
            }
            return NULL;
        }

        //Get index of node
        int indexOf(Node* n){
            Node* current = getFirst();
            int index = 0;
            while(current != NULL){
                if(current == n){
                    return index;
                }
                index++;
                current = current->getNext();
            }
            return -1;
        }

        //Get node at index
        Node* get(int index){
            Node* current = getFirst();
            for(int i = 0; i < index; i++){
                current = current->getNext();
            }
            return current;
        }

        //get the size of the list
        int size(){
            int count = 0;
            Node* current = getFirst();
            while(current != NULL){
                count++;
                current = current->getNext();
            }
            return count;
        }

    private:
        //Node variables
        T data;
        Node* next;
        Node* prev;
};

int main(){

    //Create a new list of numbers 1-10
    Node<int>* list = new Node<int>(1);
    for(int i = 2; i <= 10; i++){
        list->pushBack(i);
    }

    //Print the list forwards
    cout << "List forwards:" << endl;
    list->printList();

    //Print the list backwards
    cout << "List backwards:" << endl;
    list->printListReverse();

    //Insert a node at the 5th position
    cout << "Inserting 100 at the 5th position" << endl;
    list->insertAfter(list->get(4), 100);

    //Print the list forwards
    cout << "List forwards with 100 inserted:" << endl;
    list->printList();

    //Search the list for 100
    cout << "Searching for 100:" << endl;
    Node<int>* searchResult = list->search(100);
    if(searchResult != NULL){
        cout << searchResult->getData() << " found at: " << list->indexOf(searchResult) << endl;
    }else {
        cout << "100 not found!" << endl;
    }

    //Print the size of the list
    cout << "Size of list: " << list->size() << endl;

    return 0;
}