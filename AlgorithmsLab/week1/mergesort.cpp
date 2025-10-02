#include<iostream>
using namespace std;
void merge(int* a,int s,int e){
    int temp[e-s+1];
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=e){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else if(a[j]<a[i]){
            temp[k++]=a[j++];
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    for(int d=0;d<k;d++){
       a[d+s]=temp[d];
    }
    return;
}
void mergesort(int* a,int s,int e){
    int mid=(s+e)/2;
    if(s<e){
       mergesort(a,s,mid);
       mergesort(a,mid+1,e);
       merge(a,s,e);
    }
    return;
}
int main(){
    int a[5]={3,4,5,1,2};
    mergesort(a,0,4);
    for(int i=0;i<5;i++)
       cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}