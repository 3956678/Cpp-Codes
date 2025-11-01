#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
double bestScore=-1e9;
int bestNumColors=0;
vector<int>bestCaps,bestRegionColor,bestActive;
int n,k,m;
double alpha,beta;
vector<int>region;
vector<vector<int>>adj;
vector<vector<int>>nodes;
vector<vector<vector<int>>>options;
vector<int>caps,regionChoice;
void assignColor(vector<vector<int>> &R,vector<int> &color,int pos,int used,int totalActive){
    if(pos==k){
        int numcolors=0;
        for(int i=0;i<k;i++)
          if(color[i]+1>numcolors)
            numcolors=color[i]+1;
        long long penalty=0;
        for(int i=0;i<k;i++)
           for(int j=i+1;j<k;j++)
             if(color[i]==color[j]&&R[i][j])
                penalty+=1LL*caps[i]*caps[j];
        double score=(double)totalActive-alpha*numcolors-beta*penalty;
        if(score>bestScore){
            bestScore=score;
            bestNumColors=numcolors;
            bestCaps=caps;
            bestRegionColor=color;
        }
        return;
    }
    for(int c=0;c<used;c++){
        color[pos]=c;
        assignColor(R,color,pos+1,used,totalActive);
    }
    if(used<k){
        color[pos]=used;
        assignColor(R,color,pos+1,used+1,totalActive);
    }
}
void recurseRegions(int idx){
    if(idx==k){
        vector<int>active;
        for(int r=0;r<k;r++){
            vector<int>sel=options[r][regionChoice[r]];
            caps[r]=sel.size();
            for(int x:sel)active.push_back(x);
        }
        int totalActive=0;
        for(int r=0;r<k;r++)
          totalActive+=caps[r];
        vector<vector<int>>R(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                bool conf=false;
                for(int a:options[i][regionChoice[i]]){
                    for(int b:options[j][regionChoice[j]]){
                        if(adj[a][b]){conf=true;break;}
                    }
                    if(conf)break;
                }
                if(conf)
                 R[i][j]=R[j][i]=1;
            }
        }
        vector<int>color(k,-1);
        assignColor(R,color,0,0,totalActive);
        if(bestActive.empty()||bestScore>=0)
          bestActive=active;
        return;
    }
    for(int choice=0;choice<options[idx].size();choice++){
        regionChoice[idx]=choice;
        recurseRegions(idx+1);
    }
}
int main(){
    cin>>n>>k>>m>>alpha>>beta;
    region.resize(n);
    for(int i=0;i<n;i++)
      cin>>region[i];
    adj.assign(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u][v]=adj[v][u]=1;
        }
    nodes.assign(k,vector<int>());
    for(int i=0;i<n;i++)
      nodes[region[i]].push_back(i);
    options.assign(k,vector<vector<int>>());
    for(int r=0;r<k;r++){
        int sz=nodes[r].size();
        for(int mask=0;mask<(1<<sz);mask++){
            bool ok=true;
            for(int i=0;i<sz&&ok;i++)
               if(mask&(1<<i))
                for(int j=i+1;j<sz;j++)
                  if(mask&(1<<j))
                    if(adj[nodes[r][i]][nodes[r][j]]){
                        ok=false;break;
                        }
            if(!ok)
              continue;
            bool maximal=true;
            for(int t=0;t<sz;t++)
              if(!(mask&(1<<t)))
              {bool canadd=true;
              for(int i=0;i<sz;i++)
              if(mask&(1<<i))
              if(adj[nodes[r][i]][nodes[r][t]])
              {
                canadd=false;break;
              }
              if(canadd){
                maximal=false;break;
                }}
            if(maximal){
                vector<int>sel;
                for(int i=0;i<sz;i++)
                  if(mask&(1<<i))
                    sel.push_back(nodes[r][i]);
                    options[r].push_back(sel);
                }
        }
        if(options[r].empty())
          options[r].push_back(vector<int>());
    }
    caps.assign(k,0);
    regionChoice.assign(k,0);
    recurseRegions(0);
    cout<<fixed<<bestScore<<"\n";
    cout<<bestNumColors;
    for(int i=0;i<k;i++)cout<<" "<<bestCaps[i];
    cout<<"\n";
    sort(bestActive.begin(),bestActive.end());
    for(int i=0;i<bestActive.size();i++){
        if(i)
         cout<<" ";cout<<bestActive[i];
         }
    cout<<"\n";
    for(int i=0;i<k;i++){
        if(i)
         cout<<" ";cout<<bestRegionColor[i];
         }
    cout<<"\n";
}