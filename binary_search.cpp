#include <iostream>
using namespace std;

int binarysearch(int arr[], int size, int element)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] > element)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 5, 6, 7, 9, 10, 13, 15, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 9;
    int result = binarysearch(arr, size, element);
    if (result != -1)
    {
        cout << "Element found at index " << result;
    }
    else
    {
        cout << "element not found";
    }
    return 0;
}