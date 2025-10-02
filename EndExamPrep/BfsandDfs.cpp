#include<iostream>
#include<queue>
using namespace std;
int a[8][8];
int deg[8]={0};
bool vis1[8]={false};
bool vis2[8]={false};
void BFS(){
   queue<int> q;
   q.push(0);
   vis1[0]=true;
   while(!q.empty()){
     int val=q.front();
     cout<<val<<" ";
     q.pop();
    for(int i=0;i<deg[i];i++){
       if(!vis1[a[val][i]]){
        q.push(a[val][i]);
        vis1[a[val][i]]=true;
       }
   }
  }
   for(int i=0;i<8;i++)
     vis1[i]=false;
}
void dfs(int value){
    cout<<value<<" ";
    vis2[value]=true;
    for(int i=0;i<deg[value];i++){
        if(!vis2[a[value][i]]){
            dfs(a[value][i]);
         }
    }
}
int main(){
    a[0][deg[0]++]=1;
     a[0][deg[0]++]=2;
     a[1][deg[1]++]=5;
     a[1][deg[1]++]=7;
     a[2][deg[2]++]=3;
     a[2][deg[2]++]=4;
     a[3][deg[3]++]=2;
     a[4][deg[4]++]=2;
     a[2][deg[2]++]=0;
     a[1][deg[1]++]=0;
     a[5][deg[5]++]=1;
     a[5][deg[5]++]=6;
     a[6][deg[6]++]=5;
     a[6][deg[6]++]=8;
     a[7][deg[7]++]=1;
     a[7][deg[7]++]=8;
     a[8][deg[8]++]=6;
     a[8][deg[8]++]=7;
    BFS();
    cout<<endl;
    dfs(0);
}