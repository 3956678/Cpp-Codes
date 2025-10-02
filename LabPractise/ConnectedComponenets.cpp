#include<iostream>
using namespace std;
int a[9][9];
int deg[9];
void dfs(int v,int* flag){
    flag[v]=1;
    cout<<v<<" ";
    for(int i=0;i<deg[v];i++){
        if(flag[a[v][i]]==-1){
            dfs(a[v][i],flag);
        }
    }
}
int main(){
    int flag[9];
    for(int i=0;i<9;i++)
       flag[i]=-1; 
    int count=0;
    a[0][deg[0]++]=1;
    a[0][deg[0]++]=3;
    a[1][deg[1]++]=0;
    a[1][deg[1]++]=2;
    a[2][deg[2]++]=1;
    a[2][deg[2]++]=3;
    a[3][deg[3]++]=0;
    a[3][deg[3]++]=2;
    a[4][deg[4]++]=5;
    a[5][deg[5]++]=4;
    a[6][deg[6]++]=7;
    a[6][deg[6]++]=8;
    a[7][deg[7]++]=6;
    a[7][deg[7]++]=8;
    a[8][deg[8]++]=6;
    a[8][deg[8]++]=7;
    for(int i=0;i<=8;i++){
        if(flag[i]==-1){
            count++;
            dfs(i,flag);
            cout<<endl;
        }
    }
    cout<<"The no.of componenets are:"<<count;
}