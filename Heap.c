#include <stdio.h>
#define MAX 100

// ---------- MIN HEAP IMPLEMENTATION ----------
int minHeap[MAX];
int minSize = 0;

void minHeapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (minHeap[parent] > minHeap[index]) {
            int temp = minHeap[parent];
            minHeap[parent] = minHeap[index];
            minHeap[index] = temp;
            index = parent;
        } else break;
    }
}

void minHeapifyDown(int index) {
    int left, right, smallest;
    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < minSize && minHeap[left] < minHeap[smallest])
            smallest = left;
        if (right < minSize && minHeap[right] < minHeap[smallest])
            smallest = right;

        if (smallest != index) {
            int temp = minHeap[index];
            minHeap[index] = minHeap[smallest];
            minHeap[smallest] = temp;
            index = smallest;
        } else break;
    }
}

void insertMinHeap(int value) {
    if (minSize >= MAX) {
        printf("Min-Heap is full!\n");
        return;
    }
    minHeap[minSize] = value;
    minHeapifyUp(minSize);
    minSize++;
}

int deleteMin() {
    if (minSize <= 0) {
        printf("Min-Heap is empty!\n");
        return -1;
    }
    int root = minHeap[0];
    minHeap[0] = minHeap[minSize - 1];
    minSize--;
    minHeapifyDown(0);
    return root;
}

void printMinHeap() {
    printf("Min-Heap: ");
    for (int i = 0; i < minSize; i++)
        printf("%d ", minHeap[i]);
    printf("\n");
}

// ---------- MAX HEAP IMPLEMENTATION ----------
int maxHeap[MAX];
int maxSize = 0;

void maxHeapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (maxHeap[parent] < maxHeap[index]) {
            int temp = maxHeap[parent];
            maxHeap[parent] = maxHeap[index];
            maxHeap[index] = temp;
            index = parent;
        } else break;
    }
}

void maxHeapifyDown(int index) {
    int left, right, largest;
    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        largest = index;

        if (left < maxSize && maxHeap[left] > maxHeap[largest])
            largest = left;
        if (right < maxSize && maxHeap[right] > maxHeap[largest])
            largest = right;

        if (largest != index) {
            int temp = maxHeap[index];
            maxHeap[index] = maxHeap[largest];
            maxHeap[largest] = temp;
            index = largest;
        } else break;
    }
}

void insertMaxHeap(int value) {
    if (maxSize >= MAX) {
        printf("Max-Heap is full!\n");
        return;
    }
    maxHeap[maxSize] = value;
    maxHeapifyUp(maxSize);
    maxSize++;
}

int deleteMax() {
    if (maxSize <= 0) {
        printf("Max-Heap is empty!\n");
        return -1;
    }
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[maxSize - 1];
    maxSize--;
    maxHeapifyDown(0);
    return root;
}

void printMaxHeap() {
    printf("Max-Heap: ");
    for (int i = 0; i < maxSize; i++)
        printf("%d ", maxHeap[i]);
    printf("\n");
}

// ---------- MAIN FUNCTION ----------
int main() {
    // Min-Heap
    insertMinHeap(40);
    insertMinHeap(10);
    insertMinHeap(30);
    insertMinHeap(50);
    insertMinHeap(20);

    printMinHeap();
    printf("Deleted min: %d\n", deleteMin());
    printMinHeap();

    printf("\n");

    // Max-Heap
    insertMaxHeap(40);
    insertMaxHeap(10);
    insertMaxHeap(30);
    insertMaxHeap(50);
    insertMaxHeap(20);

    printMaxHeap();
    printf("Deleted max: %d\n", deleteMax());
    printMaxHeap();

    return 0;
}
