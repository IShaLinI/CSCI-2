//Andrew Card

#include <iostream>
#include <cmath>
#include <vector>

#define M_PI 3.14159265358979323846

using namespace std;

//Shape Class
class Shape{
    private:
        string color;
        int strokeLength;
    public:
        //Constructor
        Shape(string _color, int _strokeLength){
            color = _color;
            strokeLength = _strokeLength;
        }
        //Destructor
        virtual ~Shape(){
            cout << "Shape Destructor" << endl;
        }

        string getColor(){
            return color;
        }
        int getStrokeLength(){
            return strokeLength;
        }
        virtual void print(){
            //Print color
            cout << "Color: " << color << endl;
            //Print stroke length
            cout << "Stroke Length: " << strokeLength << endl;
        }
};

//Regular polygon class
class RegularPolygon : public Shape{
    private:
        int sides;
        double sideLength;
    public:
        //Constructor
        RegularPolygon(string _color, int _strokeLength, int _sides, double _sideLength) : Shape(_color, _strokeLength){
            sides = _sides;
            sideLength = _sideLength;
        }
        //Destructor
        ~RegularPolygon(){
            cout << "Regular Polygon Destructor" << endl;
        }

        int getSides(){
            return sides;
        }
        double getSideLength(){
            return sideLength;
        }

        double getPerimeter(){
            return sides * sideLength;
        }

        double getArea(){
            return (sides * sideLength * sideLength) / (4 * tan(M_PI / sides));
        }

        virtual void print(){
            //Print color
            cout << "Color: " << getColor() << endl;
            //Print stroke length
            cout << "Stroke Length: " << getStrokeLength() << endl;
            //Print sides
            cout << "Sides: " << sides << endl;
            //Print side length
            cout << "Side Length: " << sideLength << endl;
            //Print perimeter
            cout << "Perimeter: " << getPerimeter() << endl;
            //Print area
            cout << "Area: " << getArea() << endl;
        }
};

//Square class from regular polygon
class Square : public RegularPolygon{
    public:
        //Constructor
        Square(string _color, int _strokeLength, double _sideLength) : RegularPolygon(_color, _strokeLength, 4, _sideLength){}
        //Destructor
        virtual ~Square(){
            cout << "Square Destructor" << endl;
        }

        void print(){
            cout << "Square" << endl;
            RegularPolygon::print();
        }
};

//Isosceles triangle class from regular polygon
class IsoscelesTriangle : public RegularPolygon{
    public:
        //Constructor
        IsoscelesTriangle(string _color, int _strokeLength, double _sideLength) : RegularPolygon(_color, _strokeLength, 3, _sideLength){}
        //Destructor
        virtual ~IsoscelesTriangle(){cout << "Isosceles Triangle Destructor" << endl;}

        void print(){
            cout << "Isosceles Triangle" << endl;
            RegularPolygon::print();
        }
};

//Regular Hexagon class from regular polygon
class RegularHexagon : public RegularPolygon{
    public:
        //Constructor
        RegularHexagon(string _color, int _strokeLength, double _sideLength) : RegularPolygon(_color, _strokeLength, 6, _sideLength){}
        //Destructor
        virtual ~RegularHexagon(){cout << "Regular Hexagon Destructor" << endl;}

        void print(){
            cout << "Regular Hexagon" << endl;
            RegularPolygon::print();
        }
};

int main(){

    system("cls");

    //Vector of base class pointers
    vector<Shape*> shapes;

    //Add shapes to vector
    shapes.push_back(new Square("Red", 2, 5));
    shapes.push_back(new IsoscelesTriangle("Blue", 3, 4));
    shapes.push_back(new RegularHexagon("Green", 4, 3));

    //Print shapes
    for(Shape* shape : shapes){
        shape->print();
        cout << endl;
    }

    //Delete shapes
    for(Shape* shape : shapes){
        delete shape;
    }

    return 0;
}