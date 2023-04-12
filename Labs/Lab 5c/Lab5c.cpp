//Andrew Card

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Print vector
void printList(vector<int>& arg){
    for(int i = 0; i < arg.size(); i++){
        cout << arg[i] << endl;
    }
    cout << endl;
}

int searchListLinear(vector<int>& arg, int target, int& count){
    for(int i = 0; i < arg.size(); i++){
        count++;
        if(arg[i] == target){
            return i;
        }
    }
    return -1;
}

int searchListBinary(vector<int>& arg, int target, int& count){
    int low = 0;
    int high = arg.size() - 1;
    int mid = (low + high) / 2;
    while(low <= high){
        count++;
        if(arg[mid] == target){
            return mid;
        }
        else if(arg[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    return -1;
}

//Sorts the vector using quicksort
void quickSort(vector<int>& arg, int low, int high){
    if(low < high){
        int pivot = arg[high];
        int i = low - 1;
        for(int j = low; j < high; j++){
            if(arg[j] < pivot){
                i++;
                int temp = arg[i];
                arg[i] = arg[j];
                arg[j] = temp;
            }
        }
        int temp = arg[i + 1];
        arg[i + 1] = arg[high];
        arg[high] = temp;
        int pivotIndex = i + 1;
        quickSort(arg, low, pivotIndex - 1);
        quickSort(arg, pivotIndex + 1, high);
    }
}

int main(){

    vector<int> list;

    int linearCount = 0;
    int binaryCount = 0;
    
    //Fill vector with 100 random non duplicated ints
    for(int i = 0; i < 100; i++) {
        int temp = rand() % 1000000;
        if(searchListLinear(list, temp, linearCount) == -1){
            list.push_back(temp);
        }
        else{
            i--;
        }
    }

    linearCount = 0;

    //Print vector
    printList(list);

    cout << "Sorting..." << endl; 
      
    //Sort vector
    auto start = high_resolution_clock::now();
    quickSort(list, 0, list.size() - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    //Print time in seconds
    cout << "Time taken by function: " << duration.count() / 1000000.0 << " seconds" << endl;

    //Print vector
    printList(list);

    int searches = 10000000;

    //Start timer
    start = high_resolution_clock::now();

    //Perform 100 thousand random linear searches
    linearCount = 0;
    for(int i = 0; i < searches; i++){
        int temp = rand() % 1000000;
        searchListLinear(list, temp, linearCount);
    }

    //Stop timer
    stop = high_resolution_clock::now();

    //Calculate time
    duration = duration_cast<microseconds>(stop - start);

    //Print time in seconds
    cout << "Time taken by linear searches: " << duration.count() / 1000000.0 << " seconds" << endl;

    double lienarAverage = 1.0 * linearCount / searches;

    //Perform 100 thousand random binary searches

    //Start timer
    start = high_resolution_clock::now();

    binaryCount = 0;
    for(int i = 0; i < searches; i++){
        int temp = rand() % 1000000;
        searchListBinary(list, temp, binaryCount);
    }

    //Stop timer
    stop = high_resolution_clock::now();

    //Calculate time
    duration = duration_cast<microseconds>(stop - start);

    //Print time in seconds
    cout << "Time taken by binary searches: " << duration.count() / 1000000.0 << " seconds" << endl;

    double binaryAverage = 1.0 * binaryCount / searches;

    cout << "Linear Search Average: " << lienarAverage << endl;
    cout << "Binary Search Average: " << binaryAverage << endl;

    return 0;
}