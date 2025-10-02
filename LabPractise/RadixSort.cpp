#include<iostream>
using namespace std;
void CountingSort(int* a,int pos,int n){
    int fin[n];
    int freq[10]={0};
    for(int i=0;i<n;i++){
        freq[(a[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++)
      freq[i]+=freq[i-1];
    for(int i=0;i<n;i++)
      fin[--freq[(a[i]/pos)%10]]=a[i];
    for(int i=0;i<n;i++)
       a[i]=fin[i];
}
void RadixSort(int* a,int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max)
          max=a[i];
    }
    for(int pos=1;(max/pos)>0;pos*=10){
         CountingSort(a,pos,n);
    }
}
int main(){
    int a[5]={123,415,9,4,104};
    RadixSort(a,5);
    for(int i=0;i<5;i++)
       cout<<a[i]<<" ";
    cout<<endl;
}