#include<iostream>
using namespace std;
#define n 10
int a[n];
void heapify(int i,int j){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<j&&a[left]>a[largest])
       largest=left;
    if(right<j&&a[right]>a[largest])
       largest=right;
    if(largest!=i){
       swap(a[largest],a[i]);
       heapify(largest,j);
       return;
    }
    return;
}
int main(){
    cout<<"initialy elements are:";
    for(int i=0;i<10;i++){
      cout<<i<<" ";
      a[i]=i;
    }
    cout<<endl;
    for(int i=n/2-1;i>=0;i--)
      heapify(i,n);
    cout<<"max heap from the array is:";
    for(int i=0;i<10;i++)
      cout<<a[i]<<" ";
    cout<<endl;
}