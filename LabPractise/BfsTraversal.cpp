#include<iostream>
#include<queue>
using namespace std;
int a[9][9];
void bfs(int* deg,bool* vis){
  queue<int> q;
  q.push(0);
  vis[0]=true;
  while(!q.empty()){
       int v=q.front();
       cout<<v<<" ";
       q.pop();
       for(int i=0;i<deg[v];i++){
        if(!vis[a[v][i]])
           q.push(a[v][i]);
           vis[a[v][i]]=true;
       }
  }
  for(int i=0;i<9;i++)
    vis[i]={false};
}
int main(){
   // int a[8][8];
    int deg[9]={0};
    bool vis[9]={false};
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
    bfs(deg,vis);
    cout<<endl;
    bfs(deg,vis);
    cout<<endl;
    return 0;
}