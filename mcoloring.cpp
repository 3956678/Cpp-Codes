#include<iostream>
#include<vector>
using namespace std;
bool colourcheck(vector<vector<int>> &e,vector<int> &a,int v){
     for(int m:e[v]){
        if(a[m]==a[v])
          return false;
     }
     return true;
}
bool coloring(vector<vector<int>> &e,vector<int> &a,int v,int m){
     if(v>=a.size())
      return true;
     for(int i=1;i<=m;i++){
      a[v]=i;
      if(colourcheck(e,a,v))
        if(coloring(e,a,v+1,m))
          return true;
      a[v]=-1;
     }
     return false;
}
int minColors(vector<vector<int>> &e,vector<int> &a){
    int m=0;
    while(!coloring(e,a,0,m)){
        m++;
    }
    return m;
}
int main(){
    int n=5;
    vector<vector<int>> e(n,vector<int>(n));
    e[0]={1,2,3};
    e[1]={0,2,3};
    e[2]={0,1,3};
    e[3]={0,1,2};
    e[4]={1,3,0,2};
    vector<int> a(n,-1);
    cout<<"The minimum number of colours needed are: "<<minColors(e,a)<<endl;
    return 0;
}