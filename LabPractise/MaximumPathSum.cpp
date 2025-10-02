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
int maximumSum(Node* node,int& maximum){
    if(node==NULL){
        return 0;
    }
    int left=maximumSum(node->left,maximum);
    int right=maximumSum(node->right,maximum);
    maximum=max(maximum,left+right+node->value);
    return max(left,right)+node->value;
}
int main(){
    Node* root=NULL;
    int x;
    cout<<"Enter the value:(if -1 it exits)";
    cin>>x;
    root=create(x);
    inorder(root);
    cout<<endl;
    int maximum=0;
    maximumSum(root,maximum);
    cout<<maximum<<endl;
    return 0;
}