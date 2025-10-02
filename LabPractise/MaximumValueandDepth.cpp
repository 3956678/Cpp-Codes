#include<iostream>
#include<stack>
using namespace std;
 struct Node{
    int value;
    Node* right;
    Node* left;
    int height=0;
};
stack<int> a;
Node* createNode(int value){
    Node* node=new Node();
    node->value=value;
    return node;
}
int getHeight(Node* node){
    if(node==NULL)
       return 0;
    else
       return node->height;
}
int getMaxValue(){
    int max=a.top();
    a.pop();
    while(!a.empty()){
       if(max<a.top())
          max=a.top();
        a.pop();
    }
    return max;
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
    node->height=max(getHeight(node->left),getHeight(node->right))+1;
    return node;
}
int getMaxHeight(Node* root){
    return root->height;
}
void inorder(Node* node){
    if(node==NULL)
       return;
    inorder(node->left);
    a.push(node->value);
    cout<<node->value<<" ";
    inorder(node->right);
}
int main(){
    Node* root=NULL;
    int x,a,b;
    cout<<"Enter the value you want to enter(if enetered -1 it exits):";
    cin>>x;
    root=create(x);
    inorder(root);
    cout<<endl;
    cout<<getMaxHeight(root);
    cout<<endl;
    cout<<getMaxValue();
    cout<<endl;
    return 0;
}