#include<iostream>
using namespace std;
void countingsort(int* a,int pos,int n){
    int fin[n];
    int freq[10]={0};
    for(int i=0;i<n;i++){
        freq[(a[i]/pos)%10]++;
    }
    for(int i=1;i<(10);i++)
        freq[i]+=freq[i-1];
    for(int i=n-1;i>=0;i--)
        fin[--freq[(a[i]/pos)%10]]=a[i];
    for(int i=0;i<n;i++)
        a[i]=fin[i];
}
void radixsort(int*a,int n){
     int max=a[0];
     for(int i=1;i<n;i++){
        if(a[i]>max)
           max=a[i];
    }
    for(int pos=1;((max/pos)>0);pos*=10){
        countingsort(a,pos,n);
    }
}
int main(){
    int a[12]={542,412,333,312,213,002,001,455,986,006,982,117};
    //countingsort(a,12);
    radixsort(a,12);
    for(int i=0;i<12;i++)
      cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}