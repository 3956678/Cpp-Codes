#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &a,int s,int e){
    int i=-1,j=0;
    int p=a[e];
    while(j<e){
        if(a[j]<p){
            swap(a[++i],a[j]);
        }
        j++;
    }
    i++;
    swap(a[i],a[e]);
    return i;
}
void divide(vector<int> &a,int s,int e){
    if(s<e){
      int index=partition(a,s,e);
      divide(a,s,index-1);
      divide(a,index+1,e);
    }
}
int main(){
    vector<int> a={3,4,5,2,6,1};
    cout<<"before sorting:";
    for(auto ch:a){
        cout<<ch<<" ";
    }
    cout<<endl;
    cout<<"after sorting:";
    divide(a,0,a.size()-1);
    for(auto ch:a){
        cout<<ch<<" ";
    }
    cout<<"\n";
    return 0;
}