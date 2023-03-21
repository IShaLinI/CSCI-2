//Andrew Card

#include <iostream>

using namespace std;

class Point {
    private:
        int x, y;
    public:
        Point(int a, int b) {
            x = a;
            y = b;
        }
        virtual void print() {
            cout << "\nPoint: ";
            cout << "(" << x << "," << y << ")";
        }
        ~Point() {
            cout << "Point Destroyed!" << endl;
        }
};
class Circle : public Point {
    private:
        int r;
    public:
        Circle(int a, int b, int c) : Point(a, b) {
            r = c;
        }
        virtual void print() {
            cout << "\nCircle: ";
            cout << "center: ";
            Point::print();
            cout << " radius r = " << r;
        }
};
class Cylinder : public Circle {
    private:
        int h;
    public:
        Cylinder(int a, int b, int c, int d) : Circle(a, b, c) {
            h = d;
        }
        virtual void print() {
            cout << "\nCylinder:";
            Circle::print();
            cout << " height h = " << h;
        }
};

int main(){

   //Vector of points


    return 0;
}