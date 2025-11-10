#include <iostream>
#include <omp.h>
using namespace std;
#define size 10

struct node *hashtable[size];

struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = nullptr;
    return newnode;
}

int hashfunction(int val)
{
    return val % size;
}

void insertkey(int val)
{
    int index = hashfunction(val);
    struct node *node = createnode(val);

    if (hashtable[index] == nullptr)
    {
        cout << "Added " << val << " in hashtable at index " << index << endl;
        hashtable[index] = node;
    }
    else
    {
        node->next = hashtable[index];
        hashtable[index] = node;
        cout << "Added " << val << " in hashtable at index " << index << endl;
    }
}

void displayhashtable()
{
    cout << "\nDisplaying hashtable values \n";

    for (int i = 0; i < size; i++)
    {

        printf("[%d]->", i);
        struct node *temp = hashtable[i];
        while (temp != nullptr)
        {
            cout << temp->data << " ->";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
}

int searchvalue(int val)
{
    int index = hashfunction(val);
    struct node *temp = hashtable[index];
    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

int main()
{
    for (int i = 0; i < size; i++)
    {
        hashtable[i] = nullptr;
    }

    int keys[] = {12, 34, 43, 22, 67, 77, 86, 76, 44, 144, 12, 37, 88, 19, 55, 10, 11};
    int asize = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < asize; i++)
    {
        insertkey(keys[i]);
    }

    displayhashtable();
#pragma omp paralle for
    for (int i = 0; i < asize; i++)
    {
        int found = searchvalue(keys[i]);
#pragma omp critical
        printf("key %d  %s \n", keys[i], found ? "found" : "not found");
    }

    return 0;
}