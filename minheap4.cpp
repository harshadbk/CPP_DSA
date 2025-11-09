#include <iostream>
using namespace std;

#define MAX 100

// Global variables for heap
int minheap[MAX];
int minsize = 0;

// -----------------------------
// Function: Heapify Up (fix heap after insertion)
// -----------------------------
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        // If parent is greater than child, swap
        if (minheap[index] < minheap[parent]) {
            swap(minheap[index], minheap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

// -----------------------------
// Function: Insert into Min Heap
// -----------------------------
void insertMinHeap(int value) {
    if (minsize >= MAX) {
        cout << " Overflow: Heap is full!\n";
        return;
    }

    // Step 1: Insert at the end
    minheap[minsize] = value;

    // Step 2: Fix heap property by moving up
    heapifyUp(minsize);

    // Step 3: Increase heap size
    minsize++;

    cout << "Inserted: " << value << endl;
}

// -----------------------------
// Function: Heapify Down (fix heap after deletion)
// -----------------------------
void heapifyDown(int index) {
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        // Compare with left child
        if (left < minsize && minheap[left] < minheap[smallest])
            smallest = left;

        // Compare with right child
        if (right < minsize && minheap[right] < minheap[smallest])
            smallest = right;

        // If smallest is not the parent, swap and continue down
        if (smallest != index) {
            swap(minheap[index], minheap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

// -----------------------------
// Function: Delete Minimum Element (root)
// -----------------------------
int deleteMin() {
    if (minsize <= 0) {
        cout << "Underflow: Heap is empty!\n";
        return -1;
    }

    int root = minheap[0]; // Smallest element

    // Move last element to root
    minheap[0] = minheap[minsize - 1];
    minsize--;

    // Fix heap property
    heapifyDown(0);

    cout << " Deleted element: " << root << endl;
    return root;
}

// -----------------------------
// Function: Display Heap
// -----------------------------
void displayHeap() {
    if (minsize == 0) {
        cout << "Heap is empty!\n";
        return;
    }

    cout << "Min-Heap elements: ";
    for (int i = 0; i < minsize; i++) {
        cout << minheap[i] << " ";
    }
    cout << endl;
}

// -----------------------------
// Main Function (menu-driven)
// -----------------------------
int main() {
    int choice, value;

    while (true) {
        cout << "\n====== MIN HEAP MENU ======";
        cout << "\n1. Insert";
        cout << "\n2. Delete Min";
        cout << "\n3. Display Heap";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertMinHeap(value);
                break;

            case 2:
                deleteMin();
                break;

            case 3:
                displayHeap();
                break;

            case 4:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << " Invalid choice! Try again.\n";
        }
    }
}
