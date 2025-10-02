#include<iostream>
#include<vector>
using namespace std;
int min_distance(vector<vector<int>> &point){
    int result=0;
    int size=point.size();
    vector<int> minDis(size,999999);
    vector<bool> vis(size,false);
    minDis[0]=0;
    for(int i=0;i<size;i++){
       int u=-1;
       for(int j=0;j<size;j++){
        if(!vis[j]&&(u==-1||minDis[u]>minDis[j]))
          u=j;
       }
       vis[u]=true;
       result+=minDis[u];
       for(int j=0;j<size;j++){
        if(!vis[j]){
        int dist=abs(point[u][0]-point[j][0])+abs(point[u][1]-point[j][1]);
        if(dist<minDis[j])
          minDis[j]=dist;
       }
      }
    }
    return result;
}
int main(){
    vector<vector<int>> point;
    point={{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout<<min_distance(point)<<endl;
}