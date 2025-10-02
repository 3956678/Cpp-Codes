#include<iostream>
#include<queue>
using namespace std;
#define maxN 5
#define maxE 8
int a[maxN][maxE];
int deg[maxN]={0};
int indeg[maxN]={0};
void topo(){
    queue<int> b;
    for(int i=0;i<maxN;i++){
        if(indeg[i]==0)
          b.push(i);
    }
    while(!b.empty()){
        int u=b.front();
        cout<<u<<" ";
        b.pop();
        for(int i=0;i<deg[u];i++){
            int n=a[u][i];
            indeg[n]--;
            if(indeg[n]==0)
               b.push(n);
        }
    }
}
int main(){
    a[0][deg[0]++]=2;
    a[0][deg[0]++]=3;
    a[1][deg[1]++]=0;
    a[1][deg[1]++]=4;
    a[2][deg[2]++]=5;
    a[3][deg[3]++]=5;
    a[4][deg[4]++]=2;
    a[4][deg[4]++]=0;
    for(int i=0;i<maxN;i++){
      for(int j=0;j<deg[i];j++){
        int n=a[i][j];
        indeg[n]++;
        }
     }
     topo();
}