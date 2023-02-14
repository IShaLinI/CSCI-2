//Andrew Card

#include <iostream>

using namespace std;

template <class T>
void merge(T array1[], T array2[], int size1, int size2, T array3[]){
    for(int i = 0; i < size1; i++){
        array3[i] = array1[i];
    }
    for(int i = 0; i < size2; i++){
        array3[i + size1] = array2[i];
    }
}

template<class T>
void printArray(T array[], int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}


int main(){

    const int size1 = 5;
    const int size2 = 5;
    const int size3 = size1 + size2;

    int array1[size1] = {1, 2, 3, 4, 5};
    int array2[size2] = {6, 7, 8, 9, 10};
    int array3[size3];

    cout << "Array 1: ";
    printArray(array1, size1);
    cout << "Array 2: ";
    printArray(array2, size2);
    cout << endl;
    merge(array1, array2, size1, size2, array3);
    cout << "Array 3: ";
    printArray(array3, size3);

    string sArray1[size1] = {"one", "two", "three", "four", "five"};
    string sArray2[size2] = {"six", "seven", "eight", "nine", "ten"};
    string sArray3[size3];

    cout << "String Array 1: ";
    printArray(sArray1, size1);
    cout << "String Array 2: ";
    printArray(sArray2, size2);
    cout << endl;
    merge(sArray1, sArray2, size1, size2, sArray3);
    cout << "String Array 3: ";
    printArray(sArray3, size3);

    return 0;
}