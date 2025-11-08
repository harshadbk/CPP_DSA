#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = nullptr;

void insertnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    cout << "Inserted " << data << " value at beginning...\n";
};

void insertlast(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    struct node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = nullptr;
    cout << "Inserted " << data << " value at end ...\n";
}

void insertatposition(int data, int position)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    struct node *temp = head;
    int i = 0;
    while (i != position - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    cout << "value inserted at position " << position << endl;
}

void traverse()
{
    if (head == nullptr)
    {
        cout << "Empty Linked list ...\n";
    }
    struct node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void deleteposition(int index)
{
    struct node *ptr = head;
    struct node *prev = nullptr;
    for (int i = 0; i <= index - 1; i++)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == nullptr)
    {
        cout << "List is empty ...\n";
        return;
    }

    prev->next = ptr->next;
    free(ptr);
    cout << "deleted successfully at position " << index << endl;
}

void deletelast()
{
    struct node *temp = head;
    struct node *prev = nullptr;
    while (temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    cout << "successfully deleted last value ...\n";
}

void deletefirst()
{
    struct node *temp = head;
    head = temp->next;
    free(temp);
    cout << "Successfully deleted head Node ...\n";
}

void deletebyvalue(int value)
{
    struct node *temp = head;
    struct node *prev = nullptr;
    while (temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    if (temp == nullptr)
    {
        cout << "Value not exist in list ...\n";
    }
    cout << "Deleted node by value succefull ...\n";
}

int main()
{
    int choice, pos, val;
    do
    {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete by Value\n";
        cout << "5. Traverse\n";
        cout << "6. Exit\n";
        cout << "7. Delete by position\n";
        cout << "8. Delete Last \n";
        cout << "9. Delete First \n";
        cout << "Enter your choice: \n";

        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertnode(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertlast(val);
            break;
        case 3:
            cout << "Enter value: ";
            cin >> val;
            cout << "enter position: ";
            cin >> pos;
            insertatposition(val, pos);
            break;
        case 4:
            cout << "Enter value: ";
            cin >> val;
            deletebyvalue(val);
            break;
        case 5:
            traverse();
            break;
        case 6:
            cout << "Exiting ...";
            break;
        case 7:
            cout << "enter position: ";
            cin >> pos;
            break;
        case 8:
            deletefirst();
            break;
        case 9:
            deletelast();
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    return 0;
}