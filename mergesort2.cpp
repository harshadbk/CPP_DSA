#include <iostream>
using namespace std;

void mergesort_algorithm(int arr[], int st, int mid, int end)
{
    int size = end - st + 1;
    int merge[size];
    int idx1 = st;
    int idx2 = mid + 1;
    int x = 0;

    while (idx1 <= mid && idx2 <= end)
    {
        if (arr[idx1] < arr[idx2])
        {
            merge[x++] = arr[idx1++];
        }
        else
        {
            merge[x++] = arr[idx2++];
        }
    }
    while (idx1 <= mid)
    {
        merge[x++] = arr[idx1++];
    }

    while (idx2 <= end)
    {
         merge[x++] = arr[idx2++];
    }

    for(int i=0,j=st;i<size;i++,j++){
      arr[j] = merge[i];
    }
    
    
}

void mergesort(int arr[], int st, int end)
{
    if (st < end)
    {
        int mid = (st + end) / 2;
        mergesort(arr, st, mid);
        mergesort(arr, mid + 1, end);
        mergesort_algorithm(arr, st, mid, end);
    }
}

int main()
{
    int arr[] = {12, 34, 54, 89, 27, 65, 33};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << endl;
    }

    return 0;
}