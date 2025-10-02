#include<iostream>
using namespace std;
struct node{
    float value;
    node* next;
};
node* createNode(float value){
    node* newNode=new node();
    newNode->value=value;
    return newNode;
}
node* insert(node* head,float value){
    node* newNode=createNode(value);
    if(head==NULL){
        return newNode;
    }
    if(head->value>newNode->value){
        newNode->next=head;
        return newNode;
    }
    node* cur=head;
    node* prev=head;
    while(cur!=NULL&&cur->value<value){
        prev=cur;
        cur=cur->next;
    }
    prev->next=newNode;
    newNode->next=cur;
    return head;
}
void BucketSort(float* a,int size){
    node* Buckets[size]={NULL};
    int idx;
    for(int i=0;i<size;i++){
        idx=a[i]*size;
        Buckets[idx]=insert(Buckets[idx],a[i]);
    }
    int p=0;
    for(int i=0;i<size;i++){
        node* cur=Buckets[i];
        while(cur!=NULL){
            a[p++]=cur->value;
            cur=cur->next;
        }
    }
    cout<<endl;
}
int main(){
    float a[8]={0.13,0.45,0.12,0.89,0.75,0.63,0.66,0.39};
    BucketSort(a,8);
    for(int i=0;i<8;i++)
       cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}