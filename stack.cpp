#include<iostream>
using namespace std;

#define MAX 5
int top = -1;
int stack[MAX];

void display(){
    if(top==-1){
        cout << "Underflow condition\n";
    }
    cout<< "All elements in Stack\n";
    for(int i=top;i>=0;i--){
        cout << stack[i] << endl;
    }
}

void push(int val){
    if(top==MAX-1){
        cout << "Overflow condition cant add "<<val<<endl;
        return;
    }
    top++;
    stack[top] = val;
    printf("%d pushed into stack\n", val);
}

void pop(){
    if(top==-1){
        cout << "Underflow Condition\n";
        return;
    }

    cout << "Element popped "<<stack[top]<<endl;
    top--;
}

int main(){

    display();
    push(56);
    push(13);
    push(19);
    push(52);
    display();
    push(25);
    push(72);
    display();
    pop();
    display();
    return 0;
}