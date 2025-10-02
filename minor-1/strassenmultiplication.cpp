#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> add(const vector<vector<int>> &a,const vector<vector<int>> &b){
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    return c;
}
vector<vector<int>> sub(const vector<vector<int>> &a,const vector<vector<int>> &b){
    vector<vector<int>> c(a.size(),vector<int>(a.size(),0));
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            c[i][j]=a[i][j]-b[i][j];
        }
    }
    return c;
}
vector<vector<int>> Strassen(const vector<vector<int>> &a,const vector<vector<int>> &b){
    if(a.size()==1){
        return vector<vector<int>>{{a[0][0]*b[0][0]}};
    }
    int size=a.size()/2;
    vector<vector<int>> s1(size,vector<int>(size,0));
    vector<vector<int>> s2(size,vector<int>(size,0));
    vector<vector<int>> s3(size,vector<int>(size,0));
    vector<vector<int>> s4(size,vector<int>(size,0));
    vector<vector<int>> s5(size,vector<int>(size,0));
    vector<vector<int>> s6(size,vector<int>(size,0));
    vector<vector<int>> s7(size,vector<int>(size,0));
    vector<vector<int>> s8(size,vector<int>(size,0));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            s1[i][j]=a[i][j];
            s2[i][j]=a[i][j+size];
            s3[i][j]=a[i+size][j];
            s4[i][j]=a[i+size][j+size];
            s5[i][j]=b[i][j];
            s6[i][j]=b[i][j+size];
            s7[i][j]=b[i+size][j];
            s8[i][j]=b[i+size][j+size];
        }
    }
    vector<vector<int>> M1=Strassen(add(s1,s4),add(s5,s8));
    vector<vector<int>> M2 = Strassen(add(s3, s4), s5);
    vector<vector<int>> M3 = Strassen(s1, sub(s6, s8));
    vector<vector<int>> M4 = Strassen(s4, sub(s7, s5));
    vector<vector<int>> M5 = Strassen(add(s1, s2), s8);
    vector<vector<int>> M6 = Strassen(sub(s3, s1), add(s5, s6));
    vector<vector<int>> M7 = Strassen(sub(s2, s4), add(s7, s8));
    vector<vector<int>> C(a.size(), vector<int>(a.size(),0));
    vector<vector<int>> C11(size, vector<int>(size,0));
    vector<vector<int>> C12(size, vector<int>(size,0));
    vector<vector<int>> C21(size, vector<int>(size,0));
    vector<vector<int>> C22(size, vector<int>(size,0));
    C22=add(sub(add(M1,M3),M2),M6);
    C21=add(M2,M4);
    C12=add(M5,M3);
    C11=add(sub(add(M1,M4),M5),M7);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            C[i][j]=C11[i][j];
            C[i+size][j]=C21[i][j];
            C[i][j+size]=C12[i][j];
            C[i+size][j+size]=C22[i][j];
        }
    }
    return C;
}
int main(){
    vector<vector<int>> a={{1, 2, 3,4},
                               {5, 6, 7,8},
                               {9, 10, 11,12},
                               {13,14,15,16}};
     vector<vector<int>> b={{1, 0, 1,0},
                               {0, 1, 0,1},
                               {1, 0, 1,0},
                               {0,1,0,1}};
     vector<vector<int>> c=Strassen(a,b);
     for(int i=0;i<c.size();i++){
        for(int j=0;j<c.size();j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
     } 
     return 0;
}