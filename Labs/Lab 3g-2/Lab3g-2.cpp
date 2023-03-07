//Andrew Card

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <stdlib.h>

using namespace std;

//Circle class
class Circle {
    public:
        Circle(double r) {
            radius = r;
        }
        double circum() {
            return 2 * radius * M_PI;
        }
        double area() {
            return radius * radius * M_PI;
        }
        double radius;
};

//Double Linked Node for a circle
class CircleNode {
    public:
        CircleNode(Circle* c) {
            circle = c;
            next = NULL;
            prev = NULL;
        }
        Circle* circle;
        CircleNode* next;
        CircleNode* prev;
};

//Double Linked List of Circles
class CircleList {
    public:
        CircleList() {
            head = NULL;
            tail = NULL;
        }
        void pushBack(Circle* c) {
            CircleNode* newNode = new CircleNode(c);
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
        void print() {
            CircleNode* current = head;
            while (current != NULL) {
                cout << "Radius: " << current->circle->radius << endl;
                cout << "Circumference: " << current->circle->circum() << endl;
                cout << "Area: " << current->circle->area() << endl;
                current = current->next;
            }
        }
        
        int size(){
            int count = 0;
            CircleNode* current = head;
            while (current != NULL) {
                count++;
                current = current->next;
            }
            return count;
        }

        void clear(){
            CircleNode* current = head;
            while (current != NULL) {
                CircleNode* next = current->next;
                delete current;
                current = next;
            }
            head = NULL;
            tail = NULL;
        }

        CircleNode* head;
        CircleNode* tail;
};

int main(){

    system("CLS");

    srand(time(NULL));

    //Create a new list
    CircleList* list = new CircleList();
    
    //Create 50 Random Circles
    for (int i = 0; i < 50; i++) {
        double radius = rand() % 100 + 1;
        Circle* circle = new Circle(radius);
        list->pushBack(circle);
    }
    
    //Print the list
    list->print();

    //Show the list size:
    cout << "List Size Before: " << list->size() << endl;

    //Clear the list
    cout << "Clearing list..." << endl;
    list->clear();

    //Show the list size:
    cout << "List Size After: " << list->size() << endl;

    return 0;
}