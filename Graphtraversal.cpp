#include<iostream>
#include<queue>
using namespace std;
#define maxN 8
#define maxE 8
int a[maxN][maxE];
int deg[maxN]={0};
bool vis[maxN]={0};
bool vis2[maxN]={0};
void DFS(int v){
      vis[v]=true;
      cout<<v<<" ";
      for(int i=0;i<deg[v];i++){
        int n=a[v][i];
        if(vis[n]==false)
           DFS(n);
      }
      return;
}
void BFS(int v){
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        for(int i=0;i<deg[u];i++){
            int s=a[u][i];
            if(!vis2[s]){
                vis2[s]=true;
                q.push(s);
            }
        }
    }
}
int main(){
    a[0][deg[0]++]=1;
    a[0][deg[0]++]=3;
    a[0][deg[0]++]=2;
    a[1][deg[1]++]=4;
    a[1][deg[1]++]=7;
    a[2][deg[2]++]=0;
    a[2][deg[2]++]=5;
    a[3][deg[3]++]=0;
    a[4][deg[4]++]=1;
    a[4][deg[4]++]=5;
    a[5][deg[5]++]=6;
    a[5][deg[5]++]=4;
    a[5][deg[5]++]=2;
    a[6][deg[6]++]=5;
    a[7][deg[7]++]=1;
    cout<<"Using DFS Traversal:";
    DFS(0);
    cout<<"\n";
    cout<<"Using BFS Traversal:";
    BFS(0);
}