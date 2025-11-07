#include <iostream>
using namespace std;

#define MAX 100
int minheap[MAX];
int minsize = 0;

void minheapifyup(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (minheap[parent] > minheap[index])
        {
            int temp = minheap[parent];
            minheap[parent] = minheap[index];
            minheap[index] = temp;
            index = parent;
        }
        else
            break;
    }
}

void minheapifydown(int index){
    int left,right,smallest;
    while (1)
    {
       left = 2 * index + 1;
       right = 2 * index + 2;
       smallest = index ;
       if(left < minsize && minheap[left] < minheap[smallest]){
        smallest = left;
       } 
       if(right < minsize && minheap[right] < minheap[smallest]){
        smallest = right;
       }
       if(smallest != index){
        int temp = minheap[index];
            minheap[index] = minheap[smallest];
            minheap[smallest] = temp;
            index = smallest;
       }
       else break;
    }
}

void insertMinheap(int val)
{
    if (minsize >= MAX)
    {
        cout << "Heap is getting filled you cant add anything ...";
    }
    minheap[minsize] = val;
    minheapifyup(minsize);
    cout << "Inserted :" << val << " Successfully\n";
    minsize++;
}

void printmeanheap()
{
    cout << "Min-heap ";

    for (int i = 0; i < minsize; i++)
    {
        cout << minheap[i] << " ";
    }
}

int deleteminheap()
{
    if (minsize <= 0)
    {
        cout << "Min heap is empty";
        return -1;
    }
    int root = minheap[0];
    minheap[0] = minheap[minsize-1];
    minsize--;
    minheapifydown(0);
    return root ;
}

int main()
{
    insertMinheap(40);
    insertMinheap(20);
    insertMinheap(19);
    insertMinheap(60);
    insertMinheap(1);
    printmeanheap();
    cout << "\nDeleted value " << deleteminheap() << "\n";
    printmeanheap();

    return 0;
}