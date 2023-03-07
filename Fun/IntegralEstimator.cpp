//Andrew Card

#include <iostream>
#include <cmath>

using namespace std;

double f(double x){

    double e = 2.71828182845904523536;

    return pow(e, -2 * x);
}

double getDeltaX(double a, double b, int n){
    return (b-a)/n;
}

double midpointRule(double a, double b, int n){
    double deltaX = getDeltaX(a, b, n);
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += f(a + (i + 0.5) * deltaX);
    }
    return deltaX * sum;
}

void showMidpointEquation(double a, double b, int n){
    double deltaX = getDeltaX(a, b, n);
    cout << "The midpoint equation is: " << deltaX << " * (";
    for(int i = 0; i < n; i++){
        cout << "f(" << a << " + " << (i + 0.5) << " * " << deltaX << ")";
        if(i != n - 1){
            cout << " + ";
        }
    }
    cout << ")" << endl;
}

double trapezoidalRule(double a, double b, int n){
    double deltaX = getDeltaX(a, b, n);
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += f(a + i * deltaX) + f(a + (i + 1) * deltaX);
    }
    return 2 * (deltaX * sum / 2);
}

//show trapezoidal equation
void showTrapezoidalEquation(double a, double b, int n){
    double deltaX = getDeltaX(a, b, n);
    cout << "The trapezoidal equation is: " << deltaX << " * 2 * (";
    for(int i = 0; i < n; i++){
        cout << "f(" << a << " + " << i << " * " << deltaX << ")";
        if(i != n - 1){
            cout << " + ";
        }
    }
    cout << ")" << endl;
}

double simpsonsRule(double a, double b, int n){
    double deltaX = getDeltaX(a, b, n);
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += f(a + i * deltaX) + 4 * f(a + (i + 0.5) * deltaX) + f(a + (i + 1) * deltaX);
    }
    return deltaX * sum / 6;
}

//Find midpoint rule error
double midpointRuleError(double a, double b, int n){
    double deltaX = getDeltaX(a, b, n);
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += pow(f(a + (i + 0.5) * deltaX), 2);
    }
    return deltaX * sum;
}

int main(){

    double pi = 3.14159265358979323846;

    system("CLS");

    int n = 10;

    double lower = 1;
    double upper = 3;

    cout << "The delta x is: " << getDeltaX(lower, upper, n) << endl;
    showMidpointEquation(lower, upper, n);
    cout << "The midpoint rule gives: " << midpointRule(lower, upper, n) << endl;
    cout << "The midpoint rule error is: " << midpointRuleError(lower, upper, n) << endl;
    showTrapezoidalEquation(lower, upper, n);
    cout << "The trapezoidal rule gives: " << trapezoidalRule(lower, upper, n) << endl;
    cout << "The simpsons rule gives: " << simpsonsRule(lower, upper, n) << endl;

    return 0;
}