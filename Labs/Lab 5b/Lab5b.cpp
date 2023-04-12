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
        int temp = rand() % 100;
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

    //Input loop
    while(true){

        //Ask the user to search the list
        int target;
        cout << "Enter a number to search for: ";

        //Get user input
        cin >> target;

        //Search for the number
        int index1 = searchListLinear(list, target, linearCount);
        int index2 = searchListBinary(list, target, binaryCount);

        //Print the results
        if(index1 == -1){
            cout << "The number was not found in the list using linear search." << endl;
        }
        else{
            cout << "The number was found at index " << index1 << " using linear search, with " << linearCount << " comparisons." << endl;
        }

        if(index2 == -1){
            cout << "The number was not found in the list using binary search." << endl;
        }
        else{
            cout << "The number was found at index " << index2 << " using binary search, with " << binaryCount << " comparisons." << endl;
        }

        cout << endl;

        //Ask to run again
        char runAgain;
        cout << "Would you like to search again? (y/n): ";
        cin >> runAgain;
        if(runAgain == 'n'){
            break;
        }

    }

    return 0;
}