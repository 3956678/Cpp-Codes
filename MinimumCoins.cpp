#include<iostream>
#include<vector>
#include<map>
using namespace std;
void minimumcost(vector<int> &a,map<int,int> &b,int cost){
     int j=a.size()-1;
     while(cost>0 && j>=0){
        int count=cost/a[j];
        if(count>0){
            b[a[j]]=count;
            cost-=count*a[j];
        }
        j--;
     }
     return;
}
int main(){
   int cost;
   cout<<"Enter the cost:";
   cin>>cost;
   vector<int> a={1,5,10,50,100,500,1000};
   map<int,int> b;
   minimumcost(a,b,cost);
   cout<<"The minimum cost is:"<<endl;
   for(const auto &pair:b){
     cout<<pair.second<<" "<<pair.first<<"Rs"<<endl;
   }
   return 0;
}