#include<iostream>
#include<vector>
using namespace std;
int max_sum(int*a,int n){
    int maxi=0;
    int sum=a[0];
    int start=0,end=0,tempStart=0;
    for (int i=1;i<n;i++) {
        if (sum+a[i]<a[i]) {
            sum=a[i];
            tempStart=i;
        } else {
            sum+=a[i];
        }
        if (sum>maxi) {
            maxi=sum;
            start=tempStart;
            end=i;
        }
    }
    cout<<"The subarray is:";
     for(int i=start;i<=end;i++)
       cout<<a[i]<<" ";
     cout<<endl;
     return maxi;
}
int main(){
     int a[]={-3,-4,5,-1,0,-2,6,8};
     int maxi=max_sum(a,8);
     cout<<"Max is:"<<maxi;
     return 0;
}