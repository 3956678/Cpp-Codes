#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<int>> &b,int n){
    cout<<"solutions:"<<endl;
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) 
          cout<<b[i][j]<<" ";
        cout<<endl;
    }
}
bool safe(vector<vector<int>> &b,int r,int c,int n){
    for(int i=0;i<r;i++) 
      if(b[i][c]==1) 
       return false;
    for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--) 
       if(b[i][j]==1) 
         return false;
    for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++) 
       if(b[i][j]==1) 
         return false;
    return true;
}
bool solve(vector<vector<int>> &b,int r,int n){
    if(r==n) {
      print(b,n);
      return true;
    }
    for(int c=0;c<n;c++){
        if(safe(b,r,c,n)){
            b[r][c]=1;
            solve(b,r+1,n);
            b[r][c]=0;
        }
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter the n value:";
    cin>>n;
    vector<vector<int>> b(n,vector<int>(n,0));
    solve(b,0,n);
    return 0;
}
