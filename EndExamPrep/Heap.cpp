#include<iostream>
using namespace std;
#define n 5
int a[n];
int s=0;
void insert(int value){
     if(s>(n-1)){
        cout<<"Heap overflow"<<endl;
        return;
     }
     int p=s;
     a[s++]=value;
     while(p>0&&a[p]>a[(p-1)/2]){
        swap(a[p],a[(p-1)/2]);
        p=(p-1)/2;
     }
}
void heapify(int *a,int index,int end){
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;
    if(left<end&&a[largest]<a[left])
       largest=left;
    if(right<end&&a[largest]<a[right])
        largest=right;
    if(largest!=index){
        swap(a[largest],a[index]);
        heapify(a,largest,end);
    }
}
void deletion(){
    swap(a[0],a[s-1]);
    s--;
    heapify(a,0,s);
}
void buildMaxHeap(int* b,int size){
    for(int i=(size-1)/2;i>=0;i--){
        heapify(b,i,size);
    }
}
void heapSort(int* b,int size){
    for(int i=size-1;i>=0;i--){
        swap(b[0],b[i]);
        heapify(b,0,i-1);
    }
}
int main(){
    insert(3);
    insert(1);
    insert(4);
    insert(5);
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    deletion();
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int b[7]={4,8,9,6,1,5,7};
    buildMaxHeap(b,7);
    for(int i=0;i<7;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    heapSort(b,7);
    for(int i=0;i<7;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}