#include<iostream>
#include <stack>
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
void preorder(Node* node){
    if(node==NULL)
         return;
     cout<<node->value<<" ";
     preorder(node->left);
     preorder(node->right);
}
void postorder(Node* node){
    if(node==NULL)
       return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->value<<" ";
}
void inorderwithoutrecursion(Node* node){
    stack<Node*> s;
    //s.push(node);
    Node* currentNode=node;
    while(!s.empty()||currentNode!=NULL){
        if(currentNode==NULL&&!s.empty()){
            Node* pop=s.top();
            s.pop();
            currentNode=pop->right;
            cout<<pop->value<<" ";
        }
        else{
           s.push(currentNode);
           currentNode=currentNode->left;
        }
    }
}
void preorderwithoutrecursion(Node* node){
         stack<Node*> s;
         Node* currentNode=node;
         while(!s.empty()||currentNode!=NULL){
            if(currentNode==NULL&&!s.empty()){
                Node* pop=s.top();
                s.pop();
                currentNode=pop->right;
            }
            else{
                cout<<currentNode->value<<" ";
                s.push(currentNode);
                currentNode=currentNode->left;
            }
         }
}
void postosrderwithoutrecursion(Node* node){
    stack<Node*> s1,s2;
    Node* currentNode;
    currentNode=node;
    s1.push(node);
    while(!s1.empty()){
        Node* curr=s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left!=NULL)
           s1.push(curr->left);
        if(curr->right!=NULL)
           s1.push(curr->right);
    }
    while(!s2.empty()){
        cout<<s2.top()->value<<" ";
        s2.pop();
    }
}
int main(){
    Node* root=NULL;
    int x;
    cout<<"Enter the value:(if -1 it exits)";
    cin>>x;
    root=create(x);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorderwithoutrecursion(root);
    cout<<endl;
    preorderwithoutrecursion(root);
    cout<<endl;
    postosrderwithoutrecursion(root);
    cout<<endl;
    return 0;
}