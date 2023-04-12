//Preston Kearnan
//Lab 5a Two Search functions

#include<iostream>
#include<vector>

using namespace std;

int linearSearch(vector<int>& arg, int target);

void bubbleSort(vector<int>& arg);

int binarySearch(vector<int>& arg, int target);


int main(void) {

    srand(time(0)); 
    vector<int> numbers;
    int n = 100; 

    //1.pop with 100 randos
    for (int i = 0; i < n; i++) {
        numbers.push_back(rand() % 1001);
    }

    //2.Sort vector with any choice
    bubbleSort(numbers);


    //3. Output for the world to see
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << endl; 
    }


    //4. UI search for number
    char userI = 'y'; 
    do {

        int userR;
        cout << "Enter a Value to Search for (Values for 1-1000): "; 
        cin >> userR; 

        if (linearSearch(numbers, userI) != (-1)) {
            
            cout << "Linear Search: Integar Found!" << endl;

        }
        else {
            cout << "Integar Not Found..." << endl; 
        }

        if (binarySearch(numbers, userI) != (-1)) {

            cout << "Linear Search: Integar Found!" << endl;
        }
        else {
            cout << "Integar Not Found..." << endl;
        };


        cout << "Would you like to search for another number?(y/n)";
        cin >> userI; 
        
    } while (userI == 'y');

    return 0;
}

int linearSearch(vector<int>& arg, int target) {
    for (int i = 0; i < arg.size(); i++) {
        if (arg[i] == target) {
            return i;
        }
    }

    return -1;
}

void bubbleSort(vector<int>& arg) {

    for (int i = 0; i < arg.size() - 1; i++) {

        for (int j = 0; j < arg.size() - i - 1; j++) {

            if (arg[j] > arg[j + 1]) {
                int temp = arg[j];
                arg[j] = arg[j + 1];
                arg[j + 1] = temp;
            }
        }
    }
}

int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}