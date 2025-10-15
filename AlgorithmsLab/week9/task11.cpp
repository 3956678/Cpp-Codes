#include <iostream>
#include <vector>
#include <climits>
using namespace std;
double mcc(vector<int> &a,vector<double> &t,vector<vector<double>> &m,int i,int j) {
    if(m[i][j]!=-1.0)
        return m[i][j];
    if(i==j)
        return 0.0;
    m[i][j] = INT_MAX;
    for(int k = i; k < j; k++) {
        double cost = mcc(a,t,m,i,k)+mcc(a,t,m,k+1,j)+a[i - 1]*a[k]*a[j]*((t[i-1]+t[j-1])/2.0);
        if(cost<m[i][j])
            m[i][j] = cost;
    }
    return m[i][j];
}
int main() {
    vector<int> a;
    vector<double> t;
    int n, value;
    double e;
    cout<<"Enter number of matrices:";
    cin>>n;
    for(int i=0;i<=n;i++) {
        cout<<"Enter dimension"<<i<<": ";
        cin>>value;
        a.push_back(value);
    }
    for(int i=0;i<n;i++) {
        cout<<"Enter temperature for matrix"<<i + 1<<": ";
        cin>>e;
        t.push_back(e);
    }
    vector<vector<double>> m(n+1,vector<double>(n+1,-1.0));
    double minEnergy = mcc(a,t,m,1,n);
    cout<<"The minimum energy is:"<<minEnergy<<endl;
    return 0;
}
