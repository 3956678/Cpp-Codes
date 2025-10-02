#include<iostream>
using namespace std;
void merge(int* a,int start,int end){
    int mid=(start+end)/2;
    int temp[end-start+1];
    int i=start;
    int j=mid+1;
    int p=0;
    while(i<=mid&&j<=end){
        if(a[i]<a[j]){
          temp[p++]=a[i++];
        }
        else if(a[i]>a[j]){
            temp[p++]=a[j++];
        }
        else{
            temp[p++]=a[i++];
            temp[p++]=a[j++];
        }
    }
    while(i<=mid){
        temp[p++]=a[i++];
    }
    while(j<=end){
        temp[p++]=a[j++];
    }
    for(int k=0;k<p;k++){
        a[start+k]=temp[k];
    }
}
void sort(int* a,int start,int end){
   if(start<end){
   int mid=(start+end)/2;
   sort(a,start,mid);
   sort(a,mid+1,end);
   merge(a,start,end);
  }
}
int main(){
    int a[]={1,3,6,6,2,5};
    sort(a,0,5);
    for(int i=0;i<6;i++)
      cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}