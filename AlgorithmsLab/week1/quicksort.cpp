#include<iostream>
using namespace std;
int partition(int* a,int s,int e){
    int i=s-1;
    int j=s;
    for(j;j<e;j++){
        if(a[j]<a[e]){
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[e],a[i]);
    return i;
}
void quick(int* a,int s,int e){
    if(s<e){
        int i=partition(a,s,e);
        quick(a,s,i-1);
        quick(a,i+1,e);
    }
    return;
}
int main(){
    int a[5]={3,4,5,1,6};
    quick(a,0,4);
    for(int i=0;i<5;i++)
      cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}