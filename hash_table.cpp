#include <iostream>
#include <omp.h>
#include <stdlib.h>
using namespace std;

#define SIZE 10

struct node *hashtable[SIZE];

struct node
{
    int data;
    struct node *next;
};

int hashfunction(int key)
{
    return key % SIZE;
};

struct node *createnode(int key)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->next = nullptr;
    return newnode;
};

void insertkey(int key)
{
    int index = hashfunction(key);
    struct node *newnode = createnode(key);
    if (hashtable[index] == nullptr)
    {
        cout << "Added " << key << " in hashtable at index " << index << endl;
        hashtable[index] = newnode;
    }
    else
    {
        newnode->next = hashtable[index];
        hashtable[index] = newnode;
        cout << "Added " << key << " in hashtable at index " << index << endl;
    }
}

void displayhashtable()
{
    cout << "\nDisplaying hashtable values \n";
    for (int i = 0; i < SIZE; i++)
    {
        printf("[%d]-> ", i);
        struct node *temp = hashtable[i];
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int searchvalue(int key)
{
    int index = hashfunction(key);
    struct node *temp = hashtable[index];
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = nullptr;
    }

    int keys[] = {45, 55, 62, 26, 78, 98, 72, 88 ,87};
    int n = sizeof(keys) / sizeof(keys[0]);

#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        insertkey(keys[i]);
    }

    displayhashtable();

    cout << "\nSeraching keys in hashmap using parallel\n";
#pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        int found = searchvalue(keys[i]);
        #pragma omp critical
        {
            printf("key %d  %s \n",keys[i],found ? "found" : "not found");
        }
    }

    return 0;
}
