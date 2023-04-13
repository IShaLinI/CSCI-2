//Andrew Card

#include <iostream>
#include <vector>
#include <chrono>
#include <stdlib.h>

using namespace std;
using namespace std::chrono;

//Print Screen with updated comparison count
void printScreen(int& count, microseconds& time){
    system("CLS");
    cout << "Comparisons: " << count << "\n";
    
    //Convert time to usable varibale
    int timeInt = time.count();

    //Print time
    cout << "Time: " << timeInt << " microseconds\n" ;

}

//Print sorting screen
void printSortScreen(int& progress, int totalLoops, int& count, microseconds& time){
    system("CLS");
    cout << "Comparisons: " << count << endl;
    
    //Convert time to usable varibale
    int timeInt = time.count();

    //Print time
    cout << "Time: " << timeInt << " microseconds" << endl;

    //Print progress
    cout << "Progress: " << progress << " / " << totalLoops << endl;


}

//Print Vector
void printList(vector<int>& arg){
    for(int i = 0; i < arg.size(); i++){
        cout << arg[i] << endl;
    }
    cout << endl;
}

//Merge sort with counted comparisons
void mergeSort(vector<int>& arg, int low, int high, int& count){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(arg, low, mid, count);
        mergeSort(arg, mid + 1, high, count);
        int i = low;
        int j = mid + 1;
        int k = 0;
        vector<int> temp;
        while(i <= mid && j <= high){
            count++;
            if(arg[i] < arg[j]){
                temp.push_back(arg[i]);
                i++;
            }
            else{
                temp.push_back(arg[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(arg[i]);
            i++;
        }
        while(j <= high){
            temp.push_back(arg[j]);
            j++;
        }
        for(int i = low; i <= high; i++){
            arg[i] = temp[k];
            k++;
        }
    }
}

int main(){

    int count = 0;

    //Create vector of 100 random ints
    vector<int> list;
    for(int i = 0; i < 100; i++){
        list.push_back(rand() % 100);
    }

    //Print vector
    printList(list);

    //Sort vector

    //Start timer
    auto start = high_resolution_clock::now();
    
    mergeSort(list, 0, list.size() - 1, count);
    
    //End timer
    auto stop = high_resolution_clock::now();

    //Calculate time
    microseconds time = duration_cast<microseconds>(stop - start);

    //Print vector
    printList(list);

    //Print screen with updated comparison count
    printScreen(count, time);

    system("PAUSE");

    int sortCount = 10000;
    int progress = 0;
    count = 0;
    microseconds sortTime = microseconds(0);

    cout << "Running " << sortCount << " sorts..." << endl;

    //Generate sortCount random vectors and sort them
    for(int i = 0; i < sortCount; i++){
        vector<int> temp;
        for(int j = 0; j < 100; j++){
            temp.push_back(rand() % 100);
        }
        auto start = high_resolution_clock::now();
        mergeSort(temp, 0, temp.size() - 1, count);
        auto stop = high_resolution_clock::now();

        //Calculate time
        microseconds time = duration_cast<microseconds>(stop - start);

        //Add time to total time
        sortTime += time;

        //Increment progress
        progress++;

        //Print screen with updated comparison count
        printSortScreen(progress, sortCount, count, sortTime);

        //Print Averages
        cout << "Average Comparisons: " << 1.0 * count / (i + 1) << endl;
        cout << "Average Time: " << 1.0 * sortTime.count() / (i + 1) << " microseconds" << endl;


    }

    
    return 0;
}   