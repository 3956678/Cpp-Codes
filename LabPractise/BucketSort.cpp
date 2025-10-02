#include<iostream>
using namespace std;
struct Node{
    float value;
    Node* next;
};
Node* head=NULL;
Node* createNode(float value){
    Node* node=new Node;
    node->value=value;
    node->next=NULL;
    return node;
}
Node* Insert(Node* head,float value){
    Node* currentNode=createNode(value);
    if(head==NULL||currentNode->value<head->value){
        currentNode->next=head;
        return currentNode;
    }
    Node* cur=head;
    Node* prev=head;
    while(cur!=NULL&&cur->value<value){
        prev=cur;
        cur=cur->next;
    }
    prev->next=currentNode;
    currentNode->next=cur;
    return head;
}
void BucketSort(float* a,int size){
    Node* Buckets[size]={NULL};
    int idx;
    for(int i=0;i<size;i++){
        idx=a[i]*(size);
        Buckets[idx]=Insert(Buckets[idx],a[i]);
    }   
    int u=0;
    for(int i=0;i<size;i++){
     Node* node=Buckets[i];
     while(node!=NULL){
        a[u]=node->value;
        u++;
        node=node->next;
     }
  }
}
int main(){
    float a[8]={0.13,0.45,0.12,0.89,0.75,0.63,0.66,0.39};
    BucketSort(a,8);
    for(int i=0;i<8;i++)
       cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}