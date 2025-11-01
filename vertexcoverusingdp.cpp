#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>> &dp,vector<bool> &vis,vector<vector<int>> &g,int v,int parent){
    vis[v]=true;
    dp[v][0]=0;
    dp[v][1]=1;
    for(int u:g[v]){
        if(vis[u]==true)
         continue;
        if(u==parent)
           continue;
        dfs(dp,vis,g,u,v);
        dp[v][0]+=dp[u][1];
        dp[v][1]+=min(dp[u][1],dp[u][0]);
    }
}
int main(){
    int n=6;
    vector<vector<int>> dp(n+1,vector<int>(2));
    vector<vector<int>> g(n+1);
    vector<bool> vis(n);
     vector<pair<int,int>> edges={
        {1,2},{1,3},{2,3},{2,4},{3,5},{4,5},{4,6}
    };
    for(auto[u,v]:edges) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(dp,vis,g,1,-1);
    cout<<"The vertex cover is:"<<min(dp[1][0],dp[1][1])<<endl;
    return 0;
}