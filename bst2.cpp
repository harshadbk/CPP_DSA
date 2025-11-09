#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

struct node *insertnode(struct node *root, int val)
{
    if (root == nullptr)
    {
        cout << "Inserted " << val << " as root node." << endl;
        return createnode(val);
    }
    else if (val < root->data)
    {
        if (root->left == nullptr)
            cout << "Inserted " << val << " to the LEFT of " << root->data << endl;
        root->left = insertnode(root->left, val);
    }
    else if (val > root->data)
    {
        if (root->right == nullptr)
            cout << "Inserted " << val << " to the RIGHT of " << root->data << endl;
        root->right = insertnode(root->right, val);
    }
    else
    {
        cout << val << " already exists in the BST (duplicates not allowed)." << endl;
    }
    return root;
}

void inorder(struct node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

struct node *findmin(struct node *node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

struct node *deletenode(struct node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (val < root->data)
    {
        root->left = deletenode(root->left, val);
    }
    else if (val < root->data)
    {
        root->right = deletenode(root->left, val);
    }
    else
    {
        if (root->left == nullptr)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = findmin(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root = nullptr;
    root = insertnode(root, 65);
    root = insertnode(root, 19);
    root = insertnode(root, 71);
    root = insertnode(root, 1);
    inorder(root);
    root = deletenode(root, 19);
    inorder(root);

    return 0;
}