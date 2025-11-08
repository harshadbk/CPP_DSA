#include <iostream>
using namespace std;

#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if (rear == MAX)
    {
        cout << "Overflow Queue {Queue is empty}\n";
        return;
    }
    if (rear == -1)
        front = 0;
    queue[++rear] = val;
    cout << val << " inserted into the queue.\n";
}

void dequeue(){
    if(front==-1 || front > rear){
        cout << "Underflow condition...\n";
        return;
    }
    cout << "Deleted value from queue "<<queue[front]<<endl;
    front++;
}

void traverse(){
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    
}

int main()
{
    enqueue(87);
    enqueue(81);
    dequeue();
    traverse();
    return 0;
}