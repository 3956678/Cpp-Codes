#include<iostream>
using namespace std;
void Sort(int* a,int n){
    int fin[n];
    int max=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    int freq[max+1]={0};
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    for(int i=1;i<(max+1);i++){
        freq[i]+=freq[i-1];
    }
    for(int i=0;i<n;i++){
        fin[--freq[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++)
       a[i]=fin[i];
}
int main(){
    int a[5]={5,2,3,3,1};
    Sort(a,5);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}