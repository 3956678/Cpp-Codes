#include<iostream>
using namespace std;
struct Node{
    int value;
    int s;
    Node* left;
    Node* right;
};
Node* createNode(int value){
    Node* node=new Node();
    node->value=value;
    return node;
}
int gets(Node* node){
    if(node==NULL)
        return 0;
    return node->s;
}
Node* merge(Node* h1,Node* h2){
    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;
    if(h1->value<h2->value)
        swap(h1,h2);
    h1->right=merge(h1->right,h2);
    int sl=gets(h1->left);
    int sr=gets(h1->right);
    if(sl<sr)
       swap(h1->left,h1->right);
    h1->s=gets(h1->right)+1;
    return h1;
}
Node* insert(Node* root,int value){
    Node* temp=createNode(value);
    return merge(root,temp);
}
Node* deletion(Node* root,int& value){
    Node* newroot=merge(root->left,root->right);
    value=root->value;
    free(root);
    return newroot;
}
void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}
int main(){
     Node* root = nullptr;
    root=insert(root, 10);
    root=insert(root, 20);
    root=insert(root, 5);
    root=insert(root, 30);
    root=insert(root, 2);
    inorder(root); 
    cout<<endl;
    int val;
    root=deletion(root, val);
    cout<< "Deleted max: " << val << "\n";
    inorder(root); 
    cout<<endl;
    return 0;
}