#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node * insert(struct node *root,int val){
  if(root==NULL){
    return createNode(val);
  }
  else{
    if(root->data > val){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
  }
  return root;
}

void inorder(struct node *root){
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data<<endl;
        inorder(root->right);
    }
    
}

struct node* findMin(struct node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

struct node *deletenode(struct node *root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->data) {
        root->left = deletenode(root->left, value);
    } else if (value > root->data) {
        root->right = deletenode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    root = insert(root,50);
    insert(root,12);
    insert(root,89);
    insert(root,54);
    inorder(root);
    deletenode(root,12);
    inorder(root);

    return 0;
}