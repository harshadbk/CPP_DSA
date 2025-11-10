#include <iostream>
using namespace std;

int binarysearch(int arr[], int num, int size)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == num)
        {
            return mid;
        }
        else if (arr[mid] > num)
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
    int arr[] = {12, 15, 23, 27, 33, 39, 46, 48, 98};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binarysearch(arr, 12, size);
    if (result != -1)
    {
        cout << "Element found at index " << result;
    }
    else
    {
        cout << "Element not found \n";
    }
    return 0;
}