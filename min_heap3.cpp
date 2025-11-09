// #include <iostream>
// using namespace std;
// #define MAX 100
// int minsize = 0;
// int minheap[MAX];

// void minheapifyup(int index){
//     while (index>0)
//     {
//         int parent = (index-1)/2;
//         if(minheap[index]<minheap[parent]){
//             int temp = minheap[parent];
//             minheap[parent] = minheap[index];
//             minheap[index] = temp;
//             index = parent;
//         }
//         else
//         break;
//     }
    
// }

// void insertminheap(int val)
// {
//     if (minsize >= MAX)
//     {
//         printf("Min-Heap is full!\n");
//         return;
//     }
//     minheap[minsize] = val;
//     minheapifyup(minsize);
//     minsize++;
// }

// void traverse(){
//     for(int i=0;i<minsize;i++){
//         cout << " "<<minheap[i];
//     }
//     cout << endl;
// }

// int main()
// {
//     insertminheap(67);
//     traverse();
//     insertminheap(18);
//     traverse();
//     insertminheap(32);
//     traverse();
//     insertminheap(11);
//     traverse();

//     return 0;
// }

#include <iostream>
using namespace std;

#define MAX 100
int minheap[MAX];
int minsize = 0;

// Move newly inserted element up to maintain heap property
void minheapifyup(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (minheap[parent] > minheap[index]) {
            // swap parent and current node
            int temp = minheap[parent];
            minheap[parent] = minheap[index];
            minheap[index] = temp;
            index = parent;
        } else
            break;
    }
}

// Insert new value into min heap
void insertminheap(int val) {
    if (minsize >= MAX) {
        cout << "Min-Heap is full!" << endl;
        return;
    }

    // Step 1: Insert at the end
    minheap[minsize] = val;

    // Step 2: Move it up to correct position
    minheapifyup(minsize);

    // Step 3: Increase heap size
    minsize++;
}

// Maintain min-heap property from given index down
void minheapifydown(int index) {
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < minsize && minheap[left] < minheap[smallest])
            smallest = left;

        if (right < minsize && minheap[right] < minheap[smallest])
            smallest = right;

        if (smallest != index) {
            int temp = minheap[index];
            minheap[index] = minheap[smallest];
            minheap[smallest] = temp;
            index = smallest;
        } else
            break;
    }
}

int deleteminheap() {
    if (minsize <= 0) {
        cout << "Min-Heap is empty!" << endl;
        return -1;
    }

    int root = minheap[0];

    minheap[0] = minheap[minsize - 1];

    minsize--;

    minheapifydown(0);

    return root;
}

void printMinHeap() {
    cout << "Min-Heap: ";
    for (int i = 0; i < minsize; i++)
        cout << minheap[i] << " ";
    cout << endl;
}

int main() {
    insertminheap(78);
    printMinHeap();

    insertminheap(13);
    printMinHeap();

    insertminheap(98);
    printMinHeap();

    insertminheap(11);
    printMinHeap();

    insertminheap(1);
    printMinHeap();

    insertminheap(45);
    printMinHeap();

    cout << "Deleted element from min heap: " << deleteminheap() << endl;
    printMinHeap();

    return 0;
}