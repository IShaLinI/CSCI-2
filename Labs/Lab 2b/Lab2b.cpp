// Andrew Card

#include <iostream>

using namespace std;

int binarySearch(const int anArray[], int first, int last, int target)
{

    int index;
    if (first > last)
        index = -1;
    else
    {
        int mid = first + (last - first) / 2;
        if (target == anArray[mid])
            index = mid;
        else if (target < anArray[mid])
            index = binarySearch(anArray, first, mid - 1, target);
        else
            index = binarySearch(anArray, mid + 1, last, target);
    }

    return (index);
}

//Binary Search String Array
int binarySearch(const string anArray[], int first, int last, string target)
{

    int index;
    if (first > last)
        index = -1;
    else
    {
        int mid = first + (last - first) / 2;
        if (target == anArray[mid])
            index = mid;
        else if (target < anArray[mid])
            index = binarySearch(anArray, first, mid - 1, target);
        else
            index = binarySearch(anArray, mid + 1, last, target);
    }

    return (index);
}

int main()
{

    string words[10] = {"apple", "banana", "carrot", "dog", "elephant", "fish", "giraffe", "horse", "iguana", "jellyfish"};

    cout << binarySearch(words, 0, 9, "fish") << endl;


    return 0;
}