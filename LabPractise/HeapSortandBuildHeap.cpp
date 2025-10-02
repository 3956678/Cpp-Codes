#include<iostream>
using namespace std;
int a[5];
void heapify(int i,int j){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if((left<j)&&a[largest]<a[left])
       largest=left;
    if((right<j)&&a[largest]<a[right])
       largest=right;
    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(largest,j);
    }
}
void heapsort(){
    for(int i=4;i>=0;i--){
        swap(a[0],a[i]);
        heapify(0,i);
    }
}
void display(){
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    a[0]=1;
    a[1]=2;
    a[2]=3;
    a[3]=4;
    a[4]=5;
    for(int i=2;i>=0;i--){
        heapify(i,5);
    }
    display();
    heapsort();
    display();
}