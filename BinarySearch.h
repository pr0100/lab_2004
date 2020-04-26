#pragma once

int BinarySearch(int value, int arr[], int first, int last)
{
    int mid = 0;
    while (1)
    {
        mid = (first + last) / 2;

        if (value < arr[mid])
            last = mid - 1;
        else if (value > arr[mid])
            first = mid + 1;
        else
            return mid;
        if (first > last)
            return -1;
    }
}

int BinarySearchRecurs(int value, int arr[], int first, int last)
{
    if (last < first)
        return -1;
    int mid = (first + last) / 2;
    if (arr[mid] > value)
        return BinarySearchRecurs(value, arr, first, mid - 1);
    if (arr[mid] < value)
        return BinarySearchRecurs(value, arr, mid + 1, last);
    if (arr[mid] == value)
        return mid;
    return -1;
}
