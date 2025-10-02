#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a={2,-3,4,5,-6,7,1};
    int start=0,end=0;
    int size=a.size();
    int sum=0,max_sum=0;
    for(int i=0;i<size;i++){
        sum=sum+a[i];
        if(sum<0){
            sum=0;
            start=i+1;
        }
        if(sum>max_sum){
            max_sum=sum;
            end=i;
        }
    }
    cout<<"The maximum sum is:"<<max_sum<<endl;
    cout<<"It's subarray is:";
    for(int i=start;i<=end;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}