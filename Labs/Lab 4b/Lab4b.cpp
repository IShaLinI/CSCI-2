//Andrew Card

#include <iostream>
#include <list>

using namespace std;

//Circle Structure
struct Circle{
    double radius;
    string color;
};

//Circle color comparison class
class CircleColorCompare{
public:
    bool operator()(const Circle& c1, const Circle& c2){
        return c1.color < c2.color;
    }
};

//Circle radius comparison class
class CircleRadiusCompare{
public:
    bool operator()(const Circle& c1, const Circle& c2){
        return c1.radius < c2.radius;
    }
};

int main(){

    //Create a list of  5 circles with random radius and color dynamically
    list<Circle> myCircles;

    //Bank of colors
    string colors[5] = {"Red", "Blue", "Green", "Yellow", "Orange"};

    for(int i = 0; i < 5; i++){
        Circle newCircle;
        newCircle.radius = rand() % 10 + 1;
        newCircle.color = colors[rand() % 5];
        myCircles.push_back(newCircle);
    }

    cout << "Unsorted:" << endl;

    //Print the list
    for(list<Circle>::iterator it = myCircles.begin(); it != myCircles.end(); it++){
        cout << "Radius: " << it->radius << " Color: " << it->color << endl;
    }

    cout << endl << "Sorted by radius:" << endl;
    //Sort based on radius
    myCircles.sort(CircleRadiusCompare());

    //Print the list
    for(list<Circle>::iterator it = myCircles.begin(); it != myCircles.end(); it++){
        cout << "Radius: " << it->radius << " Color: " << it->color << endl;
    }

    cout << endl << "Sorted by color:" << endl;
    //Sort based on color
    myCircles.sort(CircleColorCompare());

    //Print the list
    for(list<Circle>::iterator it = myCircles.begin(); it != myCircles.end(); it++){
        cout << "Radius: " << it->radius << " Color: " << it->color << endl;
    }

    return 0;
}