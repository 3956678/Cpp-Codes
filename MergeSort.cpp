#include<iostream>
using namespace std;
void merge(int*a,int s,int e){
    int mid=(s+(e-s))/2;
    int temp[e-s+1];
    int i=s;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=e){
        if(a[i]>a[j]){
            temp[k++]=a[j++];
        }
        else if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[i++];
            j++;
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    for(int p=0;p<k;p++){
        a[s+p]=temp[p];
    }
}
void mergesort(int *a,int s,int e){
    int mid=(s+e)/2;
    if(s<e){
         mergesort(a,s,mid);
         mergesort(a,mid+1,e);
         merge(a,s,e);
         return;
    }
    return;
}
int main(){
    int a[5]={8,6,3,8,10};
    mergesort(a,0,4);
    for(int i=0;i<5;i++)
       cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}