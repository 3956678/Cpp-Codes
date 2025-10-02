#include<iostream>
using namespace std;
struct node{
    int value;
    node* left;
    node* sibling;
    node* parent;
    int degree=0;
};
node* createNode(int value){
    node* newNode=new node();
    newNode->value=value;
    newNode->left=newNode->sibling=NULL;
    return newNode;
}
int getDegree(node* root){
    if(root==NULL)
      return 0;
    return root->degree;
}
node* mergeTrees(node* root1,node* root2){
    if(root1==NULL)
      return root2;
    if(root2==NULL)
      return root1;
    if(getDegree(root1)>getDegree(root2)){
      root2->sibling=mergeTrees(root1,root2->sibling);
      return root2;
    }
    else{
      root1->sibling=mergeTrees(root1->sibling,root2);
      return root1;
    }
}
node* mergeHeaps(node* root1,node* root2){
    if(root1->value<root2->value)
       swap(root1,root2);
    root2->sibling=root1->left;
    root2->parent=root1;
    root1->left=root2;
    root1->degree++;
    return root1;
}
node* merge(node* root1,node* root2){
    node* root=mergeTrees(root1,root2);
    if(root==NULL)
     return root;
    node* prev=NULL;
    node* cur=root;
    node* next=root->sibling;
    while(next!=NULL){
    if(cur->degree!=next->degree||(next->sibling!=NULL&&next->sibling->degree==cur->degree)){
        prev=cur;
        cur=next;
    }
    else{
        if(cur->value>=next->value){
           cur->sibling=next->sibling;
           cur=mergeHeaps(cur,next);
        }
        else{
           if(prev==NULL)
                root=next;
            else
            prev->sibling=next;
          next=mergeHeaps(next,cur);
          cur=next;
        }
      }
    next=cur->sibling;
   }
  return root;
}
node* insert(node* root,int value){
   node* newNode=createNode(value);
   if(root==NULL)
     return newNode;
   return merge(root,newNode);   
}
void display(node* root){
   if(root==NULL)
     return;
    display(root->left);
    cout<<root->value<<" ";
    display(root->sibling);
    return;
}
int main(){
    node* root=NULL;
    root=insert(root,20);
    root=insert(root,5);
   root=insert(root,6);
    root=insert(root,25);
    root=insert(root,26);
    display(root);
    return 0;
}