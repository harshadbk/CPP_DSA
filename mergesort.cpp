#include <iostream>
using namespace std;

void merge(int arr[], int st, int mid, int ed)
{
    int size = ed - st + 1;
    int merged[size];

    int idx1 = st;       // starting index for first half
    int idx2 = mid + 1;  // starting index for second half
    int x = 0;           // index for merged array

    // Merge both halves in sorted order
    while (idx1 <= mid && idx2 <= ed)
    {
        if (arr[idx1] <= arr[idx2])
            merged[x++] = arr[idx1++];
        else
            merged[x++] = arr[idx2++];
    }

    // Copy remaining elements from left half
    while (idx1 <= mid)
        merged[x++] = arr[idx1++];

    // Copy remaining elements from right half
    while (idx2 <= ed)
        merged[x++] = arr[idx2++];

    // Copy back merged elements to original array
    for (int i = 0, j = st; i < size; i++, j++)
        arr[j] = merged[i];
}

void merge_sort_algorithm(int arr[], int st, int ed)
{
    if (st < ed)   // ✅ base condition fixed
    {
        int mid = (st + ed) / 2;

        // Sort left half
        merge_sort_algorithm(arr, st, mid);

        // Sort right half
        merge_sort_algorithm(arr, mid + 1, ed);

        // Merge sorted halves
        merge(arr, st, mid, ed);
    }
}

int main()
{
    int arr[] = {3, 6, 12, 78, 43, 45, 51, 18, 91};
    int size = sizeof(arr) / sizeof(arr[0]);

    merge_sort_algorithm(arr, 0, size - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
