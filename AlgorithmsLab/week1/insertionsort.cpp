#include<iostream>
using namespace std;
int main(){
    int a[5]={3,4,8,1,9};
    cout<<"initially:";
    for(int i=0;i<5;i++)
       cout<<a[i]<<" ";
    cout<<endl;
    for(int i=1;i<5;i++){
        int val=a[i];
        int n=i-1;
        while(val<a[n]&&n>=0){
                a[n+1]=a[n];
                n--;
        }
        a[n+1]=val;
    }
    cout<<"After Sort:";
    for(int i=0;i<5;i++)
       cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}