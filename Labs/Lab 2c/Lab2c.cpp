//Andrew Card

#include <iostream>
#include <cmath>

using namespace std;

double pi(int n){
    if(n == 0)
        return 4;
    else
        return 4 * pow(-1, n) / (2 * n + 1) + pi(n - 1);
}

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Pi: " << pi(n) << endl;

    return 0;
}