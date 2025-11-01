#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> &current){
   if(current.empty()){
    cout<<"{}"<<endl;
    return;
   }
   int s=current.size();
   for(int i=0;i<s;i++){
    cout<<current[i]<<" ";
   }
   cout<<endl;
}
int independent(vector<vector<int>> &a,vector<int> &current,int v,int n){
    int count=0;
    if(v==n){
        print(current);
        return 1;
    }
    count+=independent(a,current,v+1,n);
    bool inc=true;
    for(int s:current){
        if(a[v][s]==1){
          inc=false;
          break;
        }
    }
    if(inc==true){
        current.push_back(v);
        count+=independent(a,current,v+1,n);
        current.pop_back();
    }
    return count;
}
int main(){
    int n=5;
    vector<vector<int>> a(n,vector<int>(n));
    a[0]={0,1,1,0,0};
    a[1]={1,0,0,0,0};
    a[2]={1,0,0,1,1};
    a[3]={0,0,1,0,0};
    a[4]={0,0,1,0,0};
    vector<int> current;
    int total=independent(a,current,0,n);
    cout<<"the total are:"<<total<<endl;
    return 0;
}