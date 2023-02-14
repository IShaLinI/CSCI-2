//Andrew Card

#include <iostream>


using namespace std;

template <class T>
void deleteElement(T array[], int size, int index){
    for(int i = index; i < size - 1; i++){
        array[i] = array[i + 1];
    }
    array[size - 1] = '\0';
}

template<class T>
void printArray(T array[], int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){

    const int size = 5;

    int numbers[size] = {1, 2, 3, 4, 5};
    string words[size] = {"one", "two", "three", "four", "five"};

    printArray(numbers, size);
    printArray(words, size);
    cout << endl;
    
    deleteElement(numbers, size, 1);
    deleteElement(words, size, 4);

    printArray(numbers, size);
    printArray(words, size);


    return 0;
}