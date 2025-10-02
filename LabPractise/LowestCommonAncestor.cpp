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
    //int u;
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
void inorder(Node* node){
    if(node==NULL)
       return;
    inorder(node->left);
    cout<<node->value<<" ";
    inorder(node->right);
}
Node* lca(Node* root,int a,int b){
    if(root==NULL||root->value==a||root->value==b)
       return root;
    Node* x=lca(root->left,a,b);
    Node* y=lca(root->right,a,b);
    if(x==NULL)
       return y;
    else if(y==NULL)
       return x;
    else{
       return root;
    }
}
int main(){
    Node* root=NULL;
    int x,a,b;
    cout<<"Enter the value you want to enter(if enetered -1 it exits):";
    cin>>x;
    root=create(x);
    inorder(root);
    cout<<endl;
    cout<<"Enter value 1:";
    cin>>a;
    cout<<"Enter value 2:";
    cin>>b;
    Node* v=lca(root,a,b);
    cout<<v->value<<" ";
    return 0;
}