#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> a(4,vector<int>(4,__INT_MAX__));
    a[0][0]=0;
    a[1][1]=0;
    a[2][2]=0;
    a[3][3]=0;
    a[0][1]=1;
    a[1][0]=2;
    a[3][0]=3;
    a[3][2]=4;
    a[3][1]=5;
    a[1][2]=3;
    int n=a.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][k]!=__INT_MAX__&&a[k][j]!=__INT_MAX__)
                  a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
            }
        }
    }
    cout<<"  ";
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<" ";
        for(int j=0;j<n;j++){
            if(a[i][j]==__INT_MAX__)
              cout<<"♾️  ";
            else
              cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}