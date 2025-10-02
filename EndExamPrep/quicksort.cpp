#include<iostream>
using namespace std;
int partition(int *a,int s,int e){
    int idx=e;
    int i=s-1;
    int j=s;
    for(j;j<e;j++){
        if(a[j]<a[idx]){
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[i],a[e]);
    return i;
}
void sort(int* a,int s,int e){
    if(s<e){
        int i=partition(a,s,e);
        sort(a,s,i-1);
        sort(a,i+1,e);
    }
}
int main(){
    int a[]={2,6,3,7,5};
    sort(a,0,4);
    for(int i=0;i<5;i++)
      cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}