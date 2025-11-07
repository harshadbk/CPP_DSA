#include <iostream>
using namespace std;
#include <omp.h>

struct node
{
    int data;
    node *next;
};

node *createlist(int n)
{
    node *head = nullptr;
    node *temp = nullptr;
    for (int i = 0; i < n; i++)
    {
        node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = i + 1;
        newnode->next = nullptr;

        if (!head)
        {
            head = newnode;
        }
        else
        {
            temp->next = newnode;
        }
        temp = newnode;
    }
    return head;
};

void printlist(struct node *head)
{
    struct node *temp = head;
    while (temp)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    struct node *head = createlist(10);
    printlist(head);

    int arr[10], i = 0;
    node *temp = head;
    while (temp)
    {
        arr[i] = temp->data;
        i++;
        temp = temp->next;
    }

  #pragma omp parallel for
    for (int j = 0; j < 10; j++) {
        arr[j] *= 2;
        cout << "Thread "
             << " processed node " << arr[j] << endl;
    }

    cout << "\nAfter doubling: ";
    for (int j = 0; j < 10; j++) {
        cout << arr[j] << " ";
    }
    cout << endl;

    return 0;
}