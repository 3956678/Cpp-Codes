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
void heap(int i,int j){
    //if(i>j)
    int largest=i;
    if((2*i+1)<j&&a[2*i+1]<a[2*i+2]){
        largest=2*i+1;
    }
    if((2*i+2)<j&&a[2*i+2]<a[2*i+1]){
       largest=2*i+2;
    }
    if(largest!=i){
        swap(a[i],a[largest]);
        heap(largest,j);
    }
   return;
}
int max(){
    return a[0];
}
void increaseKey(int i,int j){
    if(a[i]<j){
        cout<<"The value is already minimum";
        return;
    }
    else{
        a[i]=j;
        heap(0,i);
        return;
    }
}
int ExtractMax(){
    if(s==0){
        cout<<"Heap underflow";
        return -1;
    }
    int p=a[0];
    s--;
    a[0]=a[s];
    if(s==0)
      return p;
    heap(0,s);
    return p;
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
     display();
     cout<<"After extracting max it is:"<<ExtractMax()<<endl;
     display();
     cout<<"The maximum is:"<<max()<<endl;
     display();
     cout<<"After increasing key"<<endl;
     int j=0;
     for(int i:a){
        if(a[j]==9){
           break;
        }
        j++;
     }
     increaseKey(j,10);
     display();
     return 0;
}