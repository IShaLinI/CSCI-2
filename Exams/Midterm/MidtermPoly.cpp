//Andrew Card

#include <iostream>
#include <vector>

using namespace std;

class Point {
    private:
        int x, y;
    public:
        Point(int a, int b);
        virtual void print();
        ~Point();
};

class Circle : public Point {
    private:
        int r;
    public:
        Circle(int a, int b, int c);
        virtual void print();
};

class Cylinder : public Circle {
    private:
        int h;
    public:
        Cylinder(int a, int b, int c, int d);
        virtual void print();
};

int main(){

    //Vector of points
    vector<Point*> points;

    //Push 10 random objects
    for(int i = 0; i < 10; i++) {

        int x = rand() % 10;
        int y = rand() % 10;
        int r = rand() % 10;
        int h = rand() % 10;

        int choice = rand() % 3;
        switch(choice) {
            case 0:
                points.push_back(new Point(x, y));
                break;
            case 1:
                points.push_back(new Circle(x, y, r));
                break;
            case 2:
                points.push_back(new Cylinder(x, y, r, h));
                break;
        }
    }

    //Print all objects
    for(int i = 0; i < points.size(); i++) {
        points[i]->print();
        cout << endl;
    }

    //Delete all objects
    for(int i = 0; i < points.size(); i++) {
        delete points[i];
    }

    return 0;
}

Point::Point(int a, int b) {
    x = a;
    y = b;
}

void Point::print() {
    cout << "\nPoint: ";
    cout << "(" << x << "," << y << ")";
}

Point::~Point() {
    cout << "Point Destroyed!" << endl;
}

Circle::Circle(int a, int b, int c) : Point(a, b) {
    r = c;
}

void Circle::print() {
    cout << "\nCircle: ";
    cout << "center: ";
    Point::print();
    cout << " radius r = " << r;
}

Cylinder::Cylinder(int a, int b, int c, int d) : Circle(a, b, c) {
    h = d;
}

void Cylinder::print() {
    cout << "\nCylinder:";
    Circle::print();
    cout << " height h = " << h;
}