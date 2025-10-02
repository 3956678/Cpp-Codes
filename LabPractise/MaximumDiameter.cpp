#include<iostream>
using namespace std;
struct Node{
    int value;
    Node* left;
    Node* right;
};
Node* head=NULL;
Node* createNode(int value){
    Node* node=new Node();
    node->value=value;
    return node;
}
Node* create(int x){
     if(x==-1)
       return NULL;
    Node* node=createNode(x);
     cout<<"Enter the value you want to insert left of"<<node->value<<":(-1 if want to exit)";
     cin>>x;
     node->left=create(x);
     cout<<"Enter the value you want to insert right of"<<node->value<<":(-1 if want to exit)";
     cin>>x;
     node->right=create(x);
     return node;
}
void inorder(Node* node) {
    if(node==NULL)
       return;
    inorder(node->left);
    cout<<node->value<<" ";
    inorder(node->right);
}
int maxDiameter(Node* root,int& diameter){
    if(root==NULL){
        return 0;
    }
    int left=maxDiameter(root->left,diameter);
    int right=maxDiameter(root->right,diameter);
    diameter=max(diameter,left+right);
    return 1+max(left,right);
}
int main(){
    Node* root=NULL;
    int x;
    cout<<"Enter the value:(if -1 it exits)";
    cin>>x;
    root=create(x);
    inorder(root);
    cout<<endl;
    int diameter=0;
    maxDiameter(root,diameter);
    cout<<diameter<<endl;
    return 0;
}