#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> add(const vector<vector<int>> &a,const vector<vector<int>> &b,int n){
    vector<vector<int>> c(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             c[i][j]=a[i][j]+b[i][j];
        }
    }
    return c;
}
vector<vector<int>> sub(const vector<vector<int>> &a,const vector<vector<int>> &b,int n){
    vector<vector<int>> c(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             c[i][j]=a[i][j]-b[i][j];
        }
    }
    return c;
}
vector<vector<int>> strassen(const vector<vector<int>> &a,const vector<vector<int>> &b,int n){
    vector<vector<int>> c(n,vector<int>(n,0));
    if(n==1){
        c[0][0]=a[0][0]*b[0][0];
        return c;
    }
    int m=n/2;
    //divide array into four parts
    vector<vector<int>> A11(m,vector<int>(m));
    vector<vector<int>> A12(m,vector<int>(m));
    vector<vector<int>> A21(m,vector<int>(m));
    vector<vector<int>> A22(m,vector<int>(m));
    vector<vector<int>> B11(m,vector<int>(m));
    vector<vector<int>> B12(m,vector<int>(m));
    vector<vector<int>> B21(m,vector<int>(m));
    vector<vector<int>> B22(m,vector<int>(m));
    vector<vector<int>> C11(m,vector<int>(m));
    vector<vector<int>> C12(m,vector<int>(m));
    vector<vector<int>> C21(m,vector<int>(m));
    vector<vector<int>> C22(m,vector<int>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            A11[i][j]=a[i][j];
            A12[i][j]=a[i][j+m];
            A21[i][j]=a[i+m][j];
            A22[i][j]=a[i+m][j+m];
            B11[i][j]=b[i][j];
            B12[i][j]=b[i][j+m];
            B21[i][j]=b[i+m][j];
            B22[i][j]=b[i+m][j+m];
        }
    }
    vector<vector<int>> M1=strassen(add(A11,A22,m),add(B11,B22,m),m);
    vector<vector<int>> M2=strassen(add(A21,A22,m),B11,m);
    vector<vector<int>> M3=strassen(A11,sub(B12,B22,m),m);
    vector<vector<int>> M4=strassen(A22,sub(B21,B11,m),m);
    vector<vector<int>> M5=strassen(add(A11,A12,m),B22,m);
    vector<vector<int>> M6=strassen(sub(A21,A11,m),add(B11,B12,m),m);
    vector<vector<int>> M7=strassen(sub(A12,A22,m),add(B21,B22,m),m);
     C11=add(sub(add(M1,M4,m),M5,m),M7,m);
     C12=add(M3,M5,m);
     C21=add(M2,M4,m);
     C22=add(sub(add(M1,M3,m),M2,m),M6,m);
    for(int i=0;i<m;i++){
      for(int j=0;j<m;j++){
        c[i][j]=C11[i][j];
        c[i][j+m]=C12[i][j];
         c[i+m][j]=C21[i][j];
        c[i+m][j+m]=C22[i][j];
      }
    }
    return c;
}
int main(){
    /*int n;
    cout<<"Enter size:";
    cin>>n;*/
    //vector<vector<int>> A(n,vector<int>(n,0)); //think of it like first n denotes
    //no.of vectors(rows) then another n like size of each vector
    //0 means initializing all to zero
    //vector<vector<int>> B(n,vector<int>(n,0));
    vector<vector<int>> a = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15, 16}};
    vector<vector<int>> b = {{16, 15, 14, 13},{12, 11, 10, 9},{8, 7, 6, 5},{4, 3, 2, 1}};
    vector<vector<int>> c(4,vector<int>(4,0));
    c=strassen(a,b,4);
    for (int i = 0; i < 4; i++) {     
        for (int j = 0; j <4; j++) {   
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
   return 0;
}