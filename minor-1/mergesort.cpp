#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &a,int s,int e){
    int mid=(s+e)/2;
    int i=s,j=mid+1;
    vector<int> b;
    while(i<=mid&&j<=e){
        if(a[i]<a[j]){
            b.push_back(a[i++]);
        }
        else if(a[i]>a[j]){
            b.push_back(a[j++]);
        }
        else{
            b.push_back(a[i]);
            i++;
            j++;
        }
    }
    while(i<=mid){
        b.push_back(a[i++]);
    }
    while(j<=e){
        b.push_back(a[j++]);
    }
    for(int i=0;i<b.size();i++)
      a[s+i]=b[i];
   return;
}
void divide(vector<int> &a,int s,int e){
    if(s<e){
        int mid=(s+e)/2;
        divide(a,s,mid);
        divide(a,mid+1,e);
        merge(a,s,e);
    }
}
int main(){
     vector<int> a={3,4,5,1,2};
     cout<<"before sorting:";
     for(auto ch:a){
        cout<<ch<<" ";
     }
     cout<<"\n";
     cout<<"After sorting:";
     divide(a,0,a.size()-1);
     for(auto ch:a){
        cout<<ch<<" ";
     }
     return 0;
}