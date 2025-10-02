#include<iostream>
#include<vector>
#include <queue>
using namespace std;
struct block{
    int a,b,c;
};
struct compare{
    bool operator()(const block& x,const block& y){ //here operator()() is overloaded
    // to compare two blocks based on their 'a' value
    // callable using compare object
        return x.a>y.a;
    }
};
vector<pair<int,int>> prims(int n,vector<vector<pair<int,int>>> &edges){
    vector<pair<int,int>> ans;
    int sum=0;
    vector<bool> visited(n,false);
    priority_queue<block,vector<block>,compare> pq; //min heap
    pq.push({0,0,-1}); //{weight,vertex,parent}
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int weight=it.a;
        int node=it.b;
        if(visited[node])
          continue;
        sum+=weight;
        visited[node]=true;
        if(it.c!=-1)
          ans.push_back({it.c, node});
        for(const auto& edge : edges[node]){
            int adjNode = edge.first;
            int edgeWeight = edge.second;
            if(visited[adjNode])continue;
            pq.push({edgeWeight,adjNode,node}); 
        }
    }
    cout<<"Minimum cost of spanning tree is: "<<sum<<endl;
    return ans;
}
int main(){
    int n=5; //number of nodes
    vector<vector<pair<int,int>>> edges(n);
    edges[0]={{1,2},{2,1}};
    edges[1]={{0,2},{2,1}};
    edges[2]={{0,1},{1,1},{3,2},{4,2}};
    edges[3]={{2,2},{4,1}};
    edges[4]={{2,2},{3,1}};
    vector<pair<int,int>> result=prims(n,edges);
    for(auto it:result){
        cout<<it.first<<"-"<<it.second<<" ";
    }
    cout<<endl;
    return 0;
}