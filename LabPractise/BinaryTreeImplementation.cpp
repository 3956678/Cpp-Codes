#include<iostream>
using namespace std;
struct Node{
    int value;
    Node* left;
    Node* right;
};
Node* createNode(int value){
      Node* node=new Node();
      node->value=value;
      return node;
}
Node* insert(Node* node,int value){
    if(node==NULL){
        return createNode(value);
    }
    if(node->value>value){
        node->left=insert(node->left,value);
    }
    else if(node->value<value){
        node->right=insert(node->right,value);
    }
    return node;
}
Node* deletion(Node* node,int value){
    if(node==NULL){
        cout<<"Cannot find it";
        return node;
    }
    if(node->value>value)
       node->left=deletion(node->left,value);
    else if(node->value<value)
       node->right=deletion(node->right,value);
    else if(node->value==value){
        Node* temp;
        if(node->left==NULL&&node->right!=NULL){
            temp=node->right;
            delete node;
            return temp;
        }
        else if(node->left!=NULL&&node->right==NULL){
            temp=node->left;
            delete node;
            return temp;
        }
        else if(node->left==NULL||node->right==NULL){
            delete node;
            return NULL;
        }
        else{
            temp=node->right;
            while(temp!=NULL)
               temp=temp->left;
            node=temp;
            delete temp;
        }
    }
    return node;
}
Node* search(Node* root,int value){
    if(root==NULL){
        cout<<"Element not found";
        return root;
    }
      if(root->value>value)
       root->left=search(root->left,value);
    else if(root->value<value)
       root->right=search(root->right,value);
    else if(root->value==value){
         cout<<"You have found the element"<<" "<<value;
         return root;
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}
int main(){
    Node* root=NULL;
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=deletion(root,20);
    root=search(root,30);
    cout<<endl;
    inorder(root);
    cout<<endl;
    return 0;
}