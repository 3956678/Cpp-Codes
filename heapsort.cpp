#include<iostream>
using namespace std;
#define n 10
int a[n];
void heap(int i,int j){
    //if(i>j)
    int largest=i;
    if((2*i+1)<j&&a[2*i+1]>a[2*i+2]){
        largest=2*i+1;
    }
    if((2*i+2)<j&&a[2*i+2]>a[2*i+1]){
       largest=2*i+2;
    }
    if(largest!=i){
        swap(a[i],a[largest]);
        heap(largest,j);
    }
   return;
}
void hsort(){
      for(int j=n-1;j>0;j--){
      swap(a[0],a[j]);
      heap(0,j);
      }
      return;
}
int main(){
     cout<<"Enter the array you want to sort using heap sort method:"<<endl;
     for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"th element:";
        cin>>a[i];
}
    cout<<endl;
    hsort();
    cout<<"the sorted array is:"<<endl;
    for(int i:a)
      cout<<i<<" ";
     return 0;
}