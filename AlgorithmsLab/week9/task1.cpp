#include<iostream>
#include<vector>
using namespace std;
int mcc(vector<int> &a,vector<double> &t,vector<vector<double>> &m,int i,int j){
    if(m[i][j]!=-1) return m[i][j];
    if(i==j) return 0;
    m[i][j]=1e9;
    for(int k=i;k<j;k++){
        m[i][j]=min(m[i][j],mcc(a,t,m,i,k)+mcc(a,t,m,k+1,j)+a[i-1]*a[k]*a[j]*((t[i-1]+t[j-1])/2.0));
    }
    return m[i][j];
}
int main(){
    vector<int> a;
    vector<double> t;
    int n,value=0;
    double e=0;
    cout<<"Enter number of matrices: ";
    cin>>n;
    for(int i=0;i<=n;i++){
        cout<<"Enter size:";
        cin>>value;
        a.push_back(value);
    }
    for(int i=0;i<n;i++){
        cout<<"Enter temperature:";
        cin>>e;
        t.push_back(e);
    }
    vector<vector<double>> m(n+1,vector<double>(n+1,-1));
    int min_Energy=mcc(a,t,m,1,n);
    min_Energy=m[1][n];
    cout<<"The minimum energy is:"<<min_Energy<<endl;
    return 0;
}