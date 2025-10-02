#include<iostream>
using namespace std;
int dc(int* a,int n){
    if(n==1){
        return a[0];
    }
    int mid=n/2;
    int lss=dc(a,mid);
    int rss=dc(a+mid,n-mid);
    int sum=0,rightsum=-1000,leftsum=-1000;
    for(int i=mid-1;i>=0;i--){
        sum+=a[i];
        leftsum=max(leftsum,sum);
    }
    sum=0;
    for(int i=mid;i<n;i++){
        sum+=a[i];
        rightsum=max(rightsum,sum);
    }
    sum=leftsum+rightsum;
    sum=max(sum,max(lss,rss));
    return sum;
}
int main(){
    int a[]={-2,-3,4,-1,-2,1,5,-3};
    int b=dc(a,8);
    cout<<"The maximum sum is:"<<b<<endl;
    return 0;
}