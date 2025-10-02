#include<iostream>
#include<queue>
using namespace std;
int a[6][6];
int indeg[6]={0};
int deg[6]={0};
void topologicalSort(){
 queue<int> q;
 for(int i=0;i<6;i++){
    if(indeg[i]==0)
      q.push(i);
 }
 while(!q.empty()){
    int value=q.front();
    cout<<value<<" ";
    q.pop();
    for(int i=0;i<deg[value];i++){
        indeg[a[value][i]]--;
        if(indeg[a[value][i]]==0){
            q.push(a[value][i]);
        }
    }
  }
  cout<<endl;
}
int main(){
    a[0][deg[0]++]=2;
     a[0][deg[0]++]=3;
     a[1][deg[1]++]=0;
     a[1][deg[1]++]=4;
     a[2][deg[2]++]=5;
     a[2][deg[2]++]=3;
     a[3][deg[3]++]=5;
     a[4][deg[4]++]=2;
     a[4][deg[4]++]=0;
     for(int i=0;i<6;i++){
        for(int j=0;j<deg[i];j++){
            indeg[a[i][j]]++;
        }
     }
     topologicalSort();
}