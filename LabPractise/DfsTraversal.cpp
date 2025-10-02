#include<iostream>
using namespace std;
int a[9][9];
bool vis[9];
int deg[9]={0};
void dfs(int v){
      vis[v]=true;
      cout<<v<<" ";
      for(int i=0;i<deg[v];i++){
        int u=a[v][i];
        if(!vis[9]){
            dfs(u);
        }
    }
}
void resetVisited(){
    for(int i=0;i<9;i++)
       vis[i]=false;
}
int main(){
    a[0][deg[0]++]=1;
    a[0][deg[0]++]=2;
    a[1][deg[1]++]=0;
    a[1][deg[1]++]=5;
    a[1][deg[1]++]=7;
    a[2][deg[2]++]=0;
    a[2][deg[2]++]=3;
    a[2][deg[2]++]=4;
    a[3][deg[3]++]=2;
    a[4][deg[4]++]=2;
    a[5][deg[5]++]=1;
    a[5][deg[5]++]=6;
    a[7][deg[7]++]=1;
    a[7][deg[7]++]=8;
    a[6][deg[6]++]=5;
    a[6][deg[6]++]=8;
    a[8][deg[8]++]=6;
    a[8][deg[8]++]=7;
    dfs(0);
    resetVisited();
    cout<<endl;
    dfs(0);
    resetVisited;
    cout<<endl;
    return 0;
}