#include<iostream>
using namespace std;
void countingSort(int *a,int pos,int size){
    int freq[10]={0};
    int b[size];
    for(int i=0;i<size;i++)
      freq[(a[i]/pos)%10]++;
    for(int i=1;i<10;i++)
      freq[i]+=freq[i-1];
    for(int i=size-1;i>=0;i--)
      b[--freq[(a[i]/pos)%10]]=a[i];
    for(int i=0;i<size;i++)
      a[i]=b[i];
}
void sort(int* a,int size){
    int max=a[0];
    for(int i=1;i<size;i++){
        if(max<a[i])
          max=a[i];
    }
    for(int pos=1;(max/pos)>0;pos*=10){
        countingSort(a,pos,size);
    }
}
int main(){
    int a[]={12,312,213,432,1234};
    sort(a,5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}