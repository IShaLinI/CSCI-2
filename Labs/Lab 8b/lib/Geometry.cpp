#include "Geometry.h"

# define M_PI 3.14159265358979323846

namespace area{
    double circle(double radius){
        return M_PI * radius * radius;
    }

    double triangle(double base, double height){
        return 0.5 * base * height;
    }

    double rectangle(double length, double width){
        return length * width;
    }

    double square(double side){
        return side * side;
    }
}