#include <iostream>
using namespace std;

#define MAX 10
int stack[MAX];
int top = -1;

void push(int val)
{
    if (top == MAX)
    {
        cout << "Stack overflow ...\n";
    }
    top++;
    stack[top] = val;
    cout << "successfully push value " << val << endl;
}

void pop()
{
    if (top == -1)
    {
        cout << "Underflow condition ...\n";
        return;
    }
    cout << "Element popped ..." << stack[top] << endl;
    top--;
}

void traverse()
{
    if (top == -1)
    {
        cout << "Underflow condition\n";
        return;
    }
    cout << "All elements in Stack \n";
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }
}

void peak()
{
    if (top == -1)
    {
        cout << "Overflow condition ...\n";
        return;
    }
    cout << "Peak value of stack is " << stack[top] << endl;
}

int main()
{
    int val,choice;
    do{
        cout << "\n---  Stack Menu ---\n";
        cout << "1. push ELement\n";
        cout << "2. pop Element\n";
        cout << "3. Traverse Element\n";
        cout << "4. Peak Element\n";
        cout << "5. Exit Element\n";
        cout << "Enter choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
           cout << "Enter element ";
           cin >> val;
           push(val);
           break;

        case 2:
           pop();
           break;
        
        case 3:
           traverse();
           break;

        case 4:
           peak();
           break;

        case 5:
          cout << "Exited...";
          break;
        
        default:
            break;
        }
    }while(choice!=5);

    return 0;
}