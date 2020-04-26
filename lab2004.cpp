#include <iostream>
#include "BinarySearch.h"
#include "Sort.h"
#include <time.h>
#include <cstdio>
#include <chrono>

/*
    Strelkov Stanislav
    RI-280002
*/

using namespace std; 

const int N = 10000;
int array1[N];

int Search(int value)
{
    for (int i = 0; i < N; i++)
    {
        if (array1[i] == value)
            return i;
    }
}

int main()
{
    clock_t start;
    double microsec;
    const int minV = -1000;
    const int maxV = 1000;
    srand(unsigned(time(0)));
    for (int i = 0; i < N; i++)
    {
        array1[i] = rand() % (maxV - minV) + minV;
    }
    const int n = 100;
    int arr[n];
    const int min = -10;
    const int max = 10;
    srand(unsigned(time(0)));
    cout << "Original array: " << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min) + min;
        cout << arr[i] << " ";
    }
    cout << endl;
    QuickSortRecurs(arr, 0, n - 1);
    cout << "Sorted array 50 elements: " << endl;
    for (int i = 0; i < 50; i++)
        cout << arr[i] << " | ";
    cout << endl;
    cout << "Binary search of 5: " << BinarySearch(5, arr, 0, n - 1) << endl;
    cout << "Recursive binary search of 5: " << BinarySearchRecurs(5, arr, 0, n - 1) << endl;  

    start = clock();
    for(int i = 0; i < 1000000; i++)
        BinarySearch(2, arr, 0, n - 1);
    microsec = ((clock() - start) / (double)CLOCKS_PER_SEC) / 1000000;
    cout << "Binary search: " << microsec << " microsec" << endl;

    start = clock();
    for (int i = 0; i < 1000000; i++)
        BinarySearchRecurs(2, arr, 0, n - 1);
    microsec = ((clock() - start) / (double)CLOCKS_PER_SEC) / 1000000;
    cout << "Binary search recursive: " << microsec << " microsec" << endl;

    start = clock();
    for (int i = 0; i < 1000000; i++)
        Search(555);
    microsec = ((clock() - start) / (double)CLOCKS_PER_SEC) / 1000000;
    cout << "Search in unsorted array: " << microsec << " microsec";
}
