#include<iostream>
using namespace std;
void countingsort(int* a,int n){
    int max=a[0];
    int fin[n];
    for(int i=1;i<n;i++){
        if(a[i]>max)
           max=a[i];
    }
    int freq[max+1]={0};
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    for(int i=1;i<(max+1);i++)
        freq[i]+=freq[i-1];
    for(int i=n-1;i>=0;i--)
        fin[--freq[a[i]]]=a[i];
    for(int i=0;i<n;i++)
        a[i]=fin[i];
}
int main(){
    int a[12]={5,4,3,3,2,2,1,5,6,6,2,7};
    countingsort(a,12);
    for(int i=0;i<12;i++)
      cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}