#include<iostream>
using namespace std;
struct node{
    int value;
    node* left;
    node* right;
    int s=1;
};
int gets(node* root){
    if(root==NULL)
       return 0;
    return root->s;
}
node* createNode(int value){
    node* newNode=new node();
    newNode->value=value;
    return newNode;
}
node* merge(node* root1,node* root2){
    if(root1==NULL)
       return root2;
    if(root2==NULL)
       return root1;
    if(root1->value<root2->value)
       swap(root1,root2);
    root1->right=merge(root1->right,root2);
    int left=gets(root1->left);
    int right=gets(root1->right);
    if(right>left)
       swap(root1->left,root1->right);
    root1->s=1+gets(root1->right);
    return root1;
}
void inorder(node* root){
    if(root==NULL)
       return;
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}
node* insert(node* root,int value){
    node* newNode=createNode(value);
    return merge(root,newNode);
}
node* deletion(node* root,int& value){
    node* newroot=merge(root->left,root->right);
    value=root->value;
    free(root);
    return newroot;
}
int main(){
    node* root=NULL;
    int value=0;
    root=insert(root,20);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,10);
    root=insert(root,2);
    inorder(root);
    cout<<endl;
    root=deletion(root,value);
    cout<<"Deleted value is:"<<value<<endl;
    inorder(root);
    cout<<endl;
    return 0;
}