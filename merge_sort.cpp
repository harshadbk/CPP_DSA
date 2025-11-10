#include <iostream>
#include <omp.h>
using namespace std;

void mergesort(int arr[], int st, int mid, int ed)
{
    int size = (ed - st) + 1;
    int merge[size];
    int idx1 = st;
    int idx2 = mid + 1;
    int x = 0;
    while (idx1 <= mid && idx2 <= ed)
    {
        if (arr[idx1] > arr[idx2])
        {
            merge[x++] = arr[idx2++];
        }
        else
        {
            merge[x++] = arr[idx1++];
        }
    }

    while (idx1 <= mid)
    {
        merge[x++] = arr[idx1++];
    }

    while (idx2 <= ed)
    {
        merge[x++] = arr[idx2++];
    }

    for (int i = 0, j = st; i < size; i++, j++)
    {
        arr[j] = merge[i];
    }
}

void merge_sort_algo(int arr[], int st, int ed)
{
    if (st < ed)
    {
        int mid = (st + ed) / 2;
#pragma omp parallel sections
        {
#pragma omp section
            {
                merge_sort_algo(arr, st, mid);
            }
#pragma omp section
            {
                merge_sort_algo(arr, mid + 1, ed);
            }
        }
        mergesort(arr, st, mid, ed);
    }
}

int main()
{
    int arr[] = {23, 12, 45, 32, 78, 76, 90, 76};
    int size = sizeof(arr) / sizeof(arr[0]);
    merge_sort_algo(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}