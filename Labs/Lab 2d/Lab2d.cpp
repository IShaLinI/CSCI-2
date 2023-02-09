//Andrew Card

#include <iostream>

using namespace std;

double powIterative(double x, int n);
double powRecursive(double x, int n);

int main(){

    cout << powIterative(2, 3) << endl;
    cout << powRecursive(2, 3) << endl;

    return 0;
}

double powIterative(double x, int n){
    double result = 1;
    for(int i = 0; i < n; i++){
        result *= x;
    }
    return result;
}

double powRecursive(double x, int n){
    if(n == 0){
        return 1;
    }
    return x * powRecursive(x, n - 1);
}