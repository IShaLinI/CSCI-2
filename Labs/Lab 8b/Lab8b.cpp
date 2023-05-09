//Andrew Card

#include <iostream>

#include "lib/Geometry.cpp"

using namespace std;

int main(){

    system("cls");

    //Unit Tests

    //Circle
    cout << "Circle" << endl;
    cout << "Expected: 12.5664" << endl;
    cout << "Actual: " << area::circle(2) << endl;

    cout << endl;

    //Triangle
    cout << "Triangle" << endl;
    cout << "Expected: 6" << endl;
    cout << "Actual: " << area::triangle(3, 4) << endl;

    cout << endl;

    //Rectangle
    cout << "Rectangle" << endl;
    cout << "Expected: 12" << endl;
    cout << "Actual: " << area::rectangle(3, 4) << endl;

    cout << endl;

    //Square
    cout << "Square" << endl;
    cout << "Expected: 9" << endl;
    cout << "Actual: " << area::square(3) << endl;

    return 0;
}