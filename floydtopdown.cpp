#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n;
vector<vector<int>> a;
vector<vector<vector<int>>> dp;
int floyd(int i,int j,int k) {  
    if(k<0)
        return a[i][j];
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    int withoutK = floyd(i,j,k-1);
    int withK = INT_MAX;
    int left = floyd(i,k,k-1);
    int right = floyd(k,j,k-1);
    if (left!=INT_MAX&&right!=INT_MAX)
        withK=left+right;
    dp[i][j][k]=min(withoutK,withK);
    return dp[i][j][k];
}
int main() {
    n=4;
    a.assign(n,vector<int>(n,INT_MAX));
    for (int i=0;i<n;i++) 
       a[i][i]=0;
    a[0][1]=1;
    a[1][0]=2;
    a[3][0]=3;
    a[3][2]=4;
    a[3][1]=5;
    a[1][2]=3;
    dp.assign(n,vector<vector<int>>(n,vector<int>(n,-1)));
    cout<<"  ";
    for(int i=1;i<=n;i++) cout<<i<<" ";
    cout<<endl;
    for(int i=0;i<n;i++) {
        cout<<i+1<<" ";
        for(int j=0;j<n;j++) {
            int ans=floyd(i,j,n-1);
            if(ans==INT_MAX)
                cout<<"♾️ ";
            else
                cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}
