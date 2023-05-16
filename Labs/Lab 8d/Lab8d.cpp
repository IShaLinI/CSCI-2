//Andrew Card

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

//Define Pi
#define M_PI 3.14159265358979323846

//Function Prototypes

//Shape Class Prototype
class Shape{
    private:
        string color;
        int strokeLength;
    public:
        //Constructor
        Shape(string _color, int _strokeLength);
        //Destructor
        ~Shape();

        string getColor();
        int getStrokeLength();
        virtual void print();
};

//Reguuar Polygon Class Prototype
class RegularPolygon : public Shape{
    private:
        int sides;
        double sideLength;
        double perimeter = -1;
        double area = -1;

        void calculatePerimeter();
        void calculateArea();

    public:
        //Constructor
        RegularPolygon(string _color, int _strokeLength, int _sides, double _sideLength);
        //Destructor
        ~RegularPolygon();

        int getSides();
        double getSideLength();
        double getPerimeter();
        double getArea();
        void print();
};

int main(){
    srand(time(0));

    RegularPolygon* polygon1;
    RegularPolygon* polygon2;
    RegularPolygon* polygon3;

    //Create a few failing polygons
    try{polygon1 = new RegularPolygon("Red", -1, 10, 5);}
    catch(string e) {cout << e << endl;}

    try{polygon2 = new RegularPolygon("Green", 1, 2, 5);}
    catch(string e) {cout << e << endl;}

    try{polygon3 = new RegularPolygon("Blue", 2, 5, 0);}
    catch(string e) {cout << e << endl;}

    //Create a few passing polygons
    try{polygon1 = new RegularPolygon("Red", 1, 10, 5);}
    catch(string e) {cout << e << endl;}

    try{polygon2 = new RegularPolygon("Green", 1, 3, 5);}
    catch(string e) {cout << e << endl;}

    try{polygon3 = new RegularPolygon("Blue", 1, 5, 5);}
    catch(string e) {cout << e << endl;}

    //Print polygons
    polygon1->print();
    polygon2->print();
    polygon3->print();

    // //Delete polygons
    delete polygon1;
    delete polygon2;
    delete polygon3;

    return 0;
}

//Shape Class Definition
Shape::Shape(string _color, int _strokeLength){
    color = _color;
    strokeLength = _strokeLength;

    if(strokeLength < 0){
        throw "Invalid stroke length: " + to_string(strokeLength);
    }
}

Shape::~Shape(){
    //cout << "Shape Destroyed" << endl;
}

string Shape::getColor(){
    return color;
}

int Shape::getStrokeLength(){
    return strokeLength;
}

void Shape::print(){
    cout << "Color: " << getColor() << endl;
    cout << "Stroke Length: " << getStrokeLength() << endl;
}

//Regular Polygon Class Definition
RegularPolygon::RegularPolygon(string _color, int _strokeLength, int _sides, double _sideLength) : Shape(_color, _strokeLength){
    sides = _sides;
    sideLength = _sideLength;

    if(sides < 3){
        throw "Invalid number of sides: " + to_string(sides);
    }
    if(sideLength < 0){
        throw "Invalid side length: " + to_string(sideLength);
    }
}

RegularPolygon::~RegularPolygon(){
    //cout << "Regular Polygon Destroyed" << endl;
}

int RegularPolygon::getSides(){
    return sides;
}

double RegularPolygon::getSideLength(){
    return sideLength;
}

double RegularPolygon::getPerimeter(){
    if(perimeter == -1){
        calculatePerimeter();
    }
    return perimeter;
}

double RegularPolygon::getArea(){
    if(area == -1){
        calculateArea();
    }
    return area;
}

void RegularPolygon::calculatePerimeter(){
    perimeter = sides * sideLength;
}

void RegularPolygon::calculateArea(){
    area = (sides * pow(sideLength, 2)) / (4 * tan(M_PI / sides));
}

void RegularPolygon::print(){
    Shape::print();
    cout << "Sides: " << getSides() << endl;
    cout << "Side Length: " << getSideLength() << endl;
    cout << "Perimeter: " << getPerimeter() << endl;
    cout << "Area: " << getArea() << endl;
}

