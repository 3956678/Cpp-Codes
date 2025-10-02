#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>> &a,int r,int c,int m,int n){
    if(r<0||c<0||r>m||c>n)
      return;
    if(a[r][c]==0)
      return;
    a[r][c]=0;
    dfs(a,r+1,c,m,n);
    dfs(a,r,c+1,m,n);
    dfs(a,r-1,c,m,n);
    dfs(a,r,c-1,m,n);
}
int main(){
    int m=4,n=5;
    //cout<<"Enter row and column:";
    //cin>>m>>n;
    vector<vector<int>> a(m,vector<int>(n));
    int count=0;
    a={{1,1,1,1,0},
        {1,1,0,1,0},
        {1,1,0,0,0},
        {0,0,0,0,0}};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                count++;
                dfs(a,i,j,m,n);
            }
        }
    }
    cout<<"The number of islands are:"<<count;
    return 0;
}