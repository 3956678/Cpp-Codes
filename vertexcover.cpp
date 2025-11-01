#include<iostream>
#include<vector>
using namespace std;
int countbits(int mask){
    int count=0;
    while(mask){
        mask&=(mask-1);
        count++;
    }
    return count;
}
int main(){
    vector<pair<int,int>> edges={{1,2},{2,1},{2,3},{3,2},{2,4},{4,2},{4,5},{5,4},{3,5},{5,3},{4,6},{6,4},{1,3},{3,1}};
    int min_v=__INT_MAX__;
    for(int mask=0;mask<(1<<7);mask++){
         bool a=true;
        for(auto [u,v]:edges){
            if((((mask>>u)&1)==0&& ((mask>>v)&1)==0)){
                a=false;
                break;
            }
        }
        if(a==true){
            min_v=min(countbits(mask),min_v);
        }
    }
    cout<<"the minimum number of nodes is:"<<min_v<<endl;
    return 0;
}