#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Drones{
    int start;
    int end;
};
bool compare(Drones d1,Drones d2){
     return d1.end<d2.end;
}
int min_sensors(vector<Drones> &d){
   sort(d.begin(),d.end(),compare);
   int count=1;
   int sensor=d[0].end;
   for(int i=1;i<d.size();i++){
    if(d[i].start>sensor){
        sensor=d[i].end;
        count++;
    }
   }
   return count;
}
int main(){
    vector<Drones> d={{1,3},{2,4},{3,5},{0,6}};
    int min=min_sensors(d);
    cout<<"The minimum number of sensors are:"<<min<<endl;
    return 0; 
}