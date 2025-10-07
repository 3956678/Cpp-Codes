#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int linearselection(vector<int> a,int left,int right,int k){
    if(k<0||k>a.size()){
        cout<<"not correct";
        return -1;
    }
    if(a.size()<=5){
        sort(a.begin(),a.end());
        return a[k];
    }
    vector<int> median;
    for(int i=left;i<=right;i+=5){
        int end=min(i+4,right);
        vector<int> group(a.begin()+i,a.begin()+end+1);
        sort(group.begin(),group.end());
        median.push_back(group[group.size()/2]);
    }
    int pivot=linearselection(median,0,median.size()-1,median.size()/2);
    int pivotindex=left;
    for(int i=left;i<=right;i++){
        if(a[i]==pivot){
            swap(a[i],a[right]);
            break;
        }
    }
    for(int i=left;i<right;i++){
        if(a[i]<pivot){
            swap(a[pivotindex],a[i]);
              pivotindex++;
        }
    }
    swap(a[pivotindex],a[right]);
    int rank=pivotindex-left+1;
    if(k==rank)
        return a[pivotindex];
    else if(k<rank)
       return linearselection(a,left,pivotindex-1,k);
    else
       return linearselection(a,pivotindex+1,right,k-rank);
}
int main(){
    vector<int> a={42,87,13,65,99,7,34,58,76,21,90,3,12,45,67};
    int k=a.size()-1;
    int i=linearselection(a,0,a.size()-1,k);
    cout<<i<<endl;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
      cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}