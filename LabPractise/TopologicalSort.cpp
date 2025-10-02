#include<iostream>
#include<queue>
using namespace std;
int a[6][5];
int indegree[6]={0};
int deg[6]={0};
void topologicalSort(){
    queue<int> q;
    for(int i=0;i<6;i++){
        if(indegree[i]==0)
           q.push(i);
    }
    //cout<<"hi"<<endl;
    while(!q.empty()){
        int s=q.front();
        cout<<s<<" ";
        q.pop();
        for(int i=0;i<5;i++){
          indegree[a[s][i]]--;
          if(indegree[a[s][i]]==0)
             q.push(a[s][i]);
        }
    }
}
int main(){
    a[0][deg[0]++]=2;
    a[0][deg[0]++]=3;
    a[1][deg[1]++]=0;
    a[1][deg[1]++]=4;
    a[2][deg[2]++]=3;
    a[2][deg[2]++]=5;
    a[3][deg[3]++]=5;
    a[4][deg[4]++]=2;
    a[4][deg[4]++]=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<deg[i];j++){
            int s=a[i][j];
            indegree[s]++;
        }
    }
    topologicalSort();
}