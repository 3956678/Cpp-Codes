#include<iostream>
using namespace std;
struct Node{
    int value;
    Node* left;
    Node* sibling;
    Node* parent;
    int degree;
};
Node* create(int s){
    Node* node=new Node();
    node->value=s;
    node->degree=0;
    node->left=NULL;
    node->sibling=NULL;
    node->parent=NULL;
    return node;
}
Node* BinomialTreeCreate(Node* node1,Node* node2){
    if(node1->value<node2->value){
        swap(node1,node2);
    }
    node2->parent=node1;
    node2->sibling=node1->left;
    node1->left=node2;
    node1->degree++;
    return node1;
}
Node* groupAllNodes(Node* node1,Node* node2){
    if(node1==NULL)
       return node2;
    if(node2==NULL)
       return node1;
    if(node1->degree<=node2->degree){
        node1->sibling=groupAllNodes(node1->sibling,node2);
        return node1;
    }
    else{
        node2->sibling=groupAllNodes(node1,node2->sibling);
        return node2;
    }
}
Node* mergeHeap(Node* node1,Node* node2){
   Node* root=groupAllNodes(node1,node2);
   if(root==NULL)
      return NULL;
   Node* previous=NULL;
   Node* current=root;
   Node* next=root->sibling;
   while(next!=NULL){
    if(current->degree!=next->degree||(next->sibling!=NULL&&next->sibling->degree==current->degree)){
            previous=current;
            current=next;
    }
    else{
        if(current->value>=next->value){
             current->sibling=next->sibling;
            current=BinomialTreeCreate(current,next);
        }
        else{
            if(previous==NULL)
               root=next;
            else
                previous->sibling=next;
           next=BinomialTreeCreate(next,current);
            current=next;
        }
    }
        next=current->sibling;
   }
   return root;
}
Node* insert(Node* root,int value){
    Node* node=create(value);
    return mergeHeap(root,node);
}
void inorder(Node* root){
    if(root==NULL)
       return;
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->sibling);
}
Node* ReverseLinkedList(Node* node){
    Node* curr=node;
    Node* next;
    Node* prev=NULL;
    while(curr!=NULL){
         next=curr->sibling;
         curr->sibling=prev;
         prev=curr;
         curr=next;
    }
    return prev;
}
Node* ExtractMin(Node* &root){
    Node* minNode=root;
    Node* minprev=NULL;
    Node* prev=NULL;
    Node* node=root;
    while(node!=NULL){
        if(node->value<minNode->value){
            minNode=node;
            minprev=prev;
        }
        prev=node;
        node=node->sibling;
    }
    if(minprev==NULL)
       root=root->sibling;
    else
       minprev->sibling=minNode->sibling;
    Node* Childnode=ReverseLinkedList(minNode->left);
    root=mergeHeap(root,Childnode);
    return minNode;
}
int main(){
    Node* root=NULL;
    root=insert(root,20);
    root=insert(root,5);
   root=insert(root,6);
    root=insert(root,25);
    //root=insert(root,26);
    inorder(root);
   Node* minNode=ExtractMin(root);
   cout<<"The Extracted minimum is:"<<minNode->value;
   cout<<endl;
   inorder(root);
   cout<<endl;
   return 0;
}