#include<iostream>
using namespace std;
void sort(int *a,int size){
    int max=a[0];
    for(int i=1;i<size;i++){
        if(max<a[i])
          max=a[i];
    }
    int b[size];
    max++;
    int freq[max]={0};
    for(int i=0;i<size;i++){
        freq[a[i]]++;
    }
    for(int i=1;i<max;i++){
        freq[i]=freq[i]+freq[i-1];
    }
    for(int i=0;i<size;i++){
        b[--freq[a[i]]]=a[i];
    }
    for(int i=0;i<size;i++){
        a[i]=b[i];
    }
}
int main(){
    int a[]={3,5,2,1,5};
    sort(a,5);
    for(int i=0;i<5;i++)
      cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}