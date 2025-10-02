#include<iostream>
using namespace std;
#define n 10
int a[n];
int s=0;
void insertion(int k){
    if(s==n){
        cout<<"Heap overflow!";
        return;
    }
    a[s]=k;
    int i=s;
    s++;
    while(i>=0&&(a[i]<a[(i-1)/2])){
        if(a[i]<a[(i-1)/2])
           swap(a[i],a[(i-1)/2]);
        i=(i-1)/2; 
    }
}
void heap(int i){
    int largest;
    if(i<=s&&a[2*i+1]<a[2*i+2]){
        largest=a[2*i+1];
        if(largest<a[i]){
           swap(a[i],a[2*i+1]);
           i=2*i+1;
           heap(i);
        }
        else
          return;
    }
    else if(i<=s&&a[2*i+2]<a[2*i+1]){
       largest=a[2*i+2];
       if(largest<a[i]){
          swap(a[i],a[2*i+2]);
           i=2*i+2;
           heap(i);
       }
       else
          return;
    }
    return;
}
void deletion(){
    if(s==0){
        cout<<"Heap underflow";
        return;
    }
    int p=a[s-1];
    s--;
    a[0]=p;
    if(s==0)
      return;
    heap(0);
}
void display(){
    cout<<"the array form of tree is:";
    for(int i=0;i<s;i++)
      cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
     insertion(30);
     insertion(9);
     insertion(20);
     insertion(8);
     insertion(3);
     insertion(16);
     insertion(12);
     insertion(5);
     insertion(4);
     deletion();
     display();
     return 0;
}