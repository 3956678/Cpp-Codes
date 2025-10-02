#include<iostream>
using namespace std;
struct Node{
    int value;
    Node* right;
    Node* left;
};
Node* createNode(int value){
    Node* node=new Node();
    node->value=value;
    return node;
}
Node* create(int x){
    if(x==-1)
       return NULL;
    Node* node=createNode(x);
    cout<<"Enter the value you want to insert for left of"<<node->value<<"(If pressed -1 it exits):";
    cin>>x;
    node->left=create(x);
    cout<<"Enter the value you want to insert for right of"<<node->value<<"(If pressed -1 it exits):";
    cin>>x;
    node->right=create(x);
    return node;
}
Node* mirror(Node* node1){
    if(node1==NULL)
       return NULL;
    Node* node2=createNode(node1->value);
    node2->left=mirror(node1->right);
    node2->right=mirror(node1->left);
    return node2;
}
void inorder(Node* node){
    if(node==NULL)
       return;
    inorder(node->left);
    cout<<node->value<<" ";
    inorder(node->right);
}
int main(){
    Node* root=NULL;
    Node* root2=NULL;
    int x;
    cout<<"Enter the value you want to enter(if enetered -1 it exits):";
    cin>>x;
    root=create(x);
    inorder(root);
    cout<<endl;
    root2=mirror(root);
    inorder(root2);
    cout<<endl;
    return 0;
}