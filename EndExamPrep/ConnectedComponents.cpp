#include<iostream>
using namespace std;
int a[9][9];
int deg[9]={0};
int flag[9]={0};
void dfs(int value){
    flag[value]=1;
    cout<<value<<" ";
    for(int i=0;i<deg[value];i++){
        if(flag[a[value][i]]==0){
            dfs(a[value][i]);
        }
    }
}
int main(){
  int count=0;
  a[0][deg[0]++]=1;
  a[0][deg[0]++]=2;
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
  cout<<"The components are:";
  for(int i=0;i<=8;i++){
    if(flag[i]==0){
       dfs(i);
       count++;
       cout<<endl;
    }
  }
  cout<<"The number of components are:"<<count<<endl;
}