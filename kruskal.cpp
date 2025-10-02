#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge{
    int u,v,wt;
};
struct compare{
    bool operator()(edge a,edge b){
        return a.wt<b.wt;
    }
};
int findParent(int u,vector<int> &parent){
    if(u==parent[u]) return u;
    return parent[u]=findParent(parent[u],parent);
}
void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
    u=findParent(u,parent);
    v=findParent(v,parent);
    if(u==v) return;
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    } 
}
int kruskal(int v,vector<edge> &edges){
    sort(edges.begin(),edges.end(),compare());
    vector<int> parent(v,0);
    vector<int> rank(v,0);
    int weight=0;
    for(int i=0;i<v;i++) parent[i]=i;
    for(auto it:edges){
        int u=findParent(it.u,parent);
        int v=findParent(it.v,parent);
        if(u!=v){
            weight+=it.wt;
            unionSet(u,v,parent,rank);
        }
    }
    return weight;
}
int main(){
    int v=4;
    vector<edge> edges;
    edges.push_back({0,1,2});
    edges.push_back({1,2,3});
    edges.push_back({0,3,1});
    edges.push_back({3,2,5});
    edges.push_back({1,3,3});
    cout<<"Minimum Spanning Tree weight is: "<<kruskal(v,edges)<<endl;
    return 0;
}