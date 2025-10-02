#include<iostream>
using namespace std;
void mergeSort(int* a,int s,int e){
    int mid=(s+(e-s))/2;
    int temp[e-s+1];
    int k=0;
    int i=s;
    int j=mid+1;
    while(i<=mid&&j<=e){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else if(a[j]<a[i]){
            temp[k++]=a[j++];
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
    return;
}
void merge(int* a,int s,int e){
    int mid=(s+e)/2;
    if(s<e){
        merge(a,s,mid);
        merge(a,mid+1,e);
        mergeSort(a,s,e);
        return;
    }
    return;
}
int main(){
    int a[]={2,1,7,9,8};
    merge(a,0,4);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    return 0;
}
