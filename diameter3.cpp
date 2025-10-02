#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;
    int rightheight = 0;
    int leftheight = 0;
};
void inorder(Node *root)
{
    if (root != 0)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int leftheight(Node *node)
{
    if (node == 0)
    {
        return 0;
    }
    return node->leftheight;
}
int rightheight(Node *node)
{
    if (node == 0)
    {
        return 0;
    }
    return node->rightheight;
}
int maximum(int a, int b)
{
    return a > b ? a : b;
}
Node *create()
{
    int x;
    cout << "Enter data to be inserted (-1 to stop creating node)\n";
    cin >> x;
    if (x == -1)
    {
        return 0;
    }
    else
    {
        Node *node = new Node();
        node->data = x;
        cout << " left child of " << x << ":\n ";
        node->left = create();
        cout << " right child of " << x << " :\n";
        node->right = create();
        node->leftheight = maximum(leftheight(node->left), rightheight(node->left)) + 1;
        node->rightheight = maximum(leftheight(node->right), rightheight(node->right)) + 1;
        return node;
    }
}
void print(Node *node)
{   
    if (leftheight(node) == 1&& rightheight(node) == 1)
    {
        cout << node->data;
        return;
    }
    
    else if (rightheight(node) == 1)
    {
        print(node->left);
        cout << node->data;
        return;
    }
    else if (leftheight(node) == 1)
    {
        cout << node->data;
        print(node->right);
    }
    else if(leftheight(node)>=rightheight(node)){
        print(node->left);
        cout<<node->data;
    }
    else{
        cout<<node->data;
        print(node->right);
    return;
}
}
int main()
{
    Node *node = create();
    int diameter = leftheight(node) + rightheight(node) - 1;
    cout << diameter << "\n";
    print(node->left);
    cout << node->data;
    print(node->right);
}