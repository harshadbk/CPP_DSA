#include<iostream>
using namespace std;

struct node {
  int data;
  node *next;
};

node *head = nullptr;

void insert_beginning(int value){ 
   struct node *new_node = (struct node *) malloc (sizeof(struct node));
   new_node->data=value;
   new_node->next=head;
   head=new_node;
   cout << "Inserted " << value << " at beginning.\n";
}

void insertAtEnd(int value){
   struct node *newnode = (struct node *) malloc (sizeof(struct node));
   newnode->data=value;
   struct node *p = head;
   while(p->next!=nullptr){
    p=p->next;
   }
   p->next=newnode;
   newnode->next = nullptr;
}

void insertAtPosition(int value,int position){
    struct node *newnode = (struct node *) malloc (sizeof(struct node));
    newnode->data = value;
    struct node *ptr = head;
    int i=0;
    while(i != position-1){
      ptr = ptr->next;
      i++;
    } 
    newnode->next = ptr->next;
    ptr->next=newnode;
}

void traverse(){
    if(head==nullptr){
        cout<<"List is empty";
    }

    struct node *temp = head;
    while(temp!=nullptr){
        cout << temp->data <<"->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void deleteNode(int index){
    struct node *ptr = head;
    struct node *prev = nullptr;

    for(int i=0;i<index-1;i++){
        prev = ptr;
        ptr = ptr->next;
    }

      if (ptr == nullptr) {
        cout << "Invalid position!\n";
        return;
    }
     prev->next = ptr->next;
     free(ptr);
     cout << "After deleting element at position "<<index<<endl;
}

int main(){
    int choice, value, pos;
     do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete by Value\n";
        cout << "5. Traverse\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert_beginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value\n";
                cin >> value;
                cout << "Enter position:";
                cin >> pos;
                insertAtPosition(value, pos);
                break;
            case 4:
                cout << "Enter Index to delete: ";
                cin >> value;
                deleteNode(value);
                break;
            case 5:
                traverse();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}