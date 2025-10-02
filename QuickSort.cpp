#include<iostream>
using namespace std;
int partition(int *a,int s,int e){
    int p=a[e];
    int i=s-1;
    int j=s;
    for(j;j<e;j++){
        if(a[j]<p){
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[e],a[i]);
    return i;
}
void quicksort(int* a,int s,int e){
    if(s<e){
       int i=partition(a,s,e);
       quicksort(a,s,i-1);
       quicksort(a,i+1,e);
    }
    return;
}
int main(){
    int a[5]={6,5,1,3,2};
    quicksort(a,0,4);
    for(int i=0;i<5;i++)
       cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}