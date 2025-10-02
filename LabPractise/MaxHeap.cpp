#include<iostream>
using namespace std;
int a[5];
#define n 5
int s=0;
void Insert(int value){
    if(s==n-1){
        cout<<"Heap Overflow!";
        return;
    }
    a[s]=value;
    int i=s++;
    while(i>0&&a[i]>a[(i-1)/2]){
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}
void heapify(int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<s&&a[largest]<a[left])
        largest=left;
    if(right<s&&a[largest]<a[right])
        largest=right;
    if(largest!=i){
        swap(a[i],a[largest]);
    heapify(largest);
    }
}
void deletion(){
    if(s==0){
        cout<<"HeapOverflow";
        return;
    }
    a[0]=a[s-1];
    s--;
    heapify(0);
}
void display(){
    for(int i=0;i<s;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    Insert(1);
    Insert(2);
    Insert(3);
    display();
    deletion();
    display();
}