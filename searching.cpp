#include<iostream>
#include<omp.h>
using namespace std;

int searchlinear(int arr[],int size,int element){
    #pragma omp parallel for
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {23,43,56,76,12,28,78};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element = 56;
    int result = searchlinear(arr,size,element);
    if(result != -1){
        cout << "Element found at index "<<result;
    }
    else{
        cout << "element not found";
    }
    return 0;
}