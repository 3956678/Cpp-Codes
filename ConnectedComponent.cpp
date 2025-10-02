#include <iostream>
using namespace std;
#define maxN 8
#define maxE 8
int a[maxN][maxE];
int deg[maxN] = {0};
void DFS(int v, int flag[])
{
    flag[v] = 1;
    cout <<  v << " ";
    for (int i = 0; i < deg[v]; i++)
    {
        int n = a[v][i];
        if (flag[n] == -1)
            DFS(n, flag);
    }
    return;
}
void connectedcomp()
{   int flag[8];
    for (int i = 0; i < 8; i++)
    {
         flag[i] = -1;
    }
    int count = 0;
    for (int v = 0; v < 8; v++)
    {
        {
            if (flag[v] == -1)
            {   cout<<"connected elements :";
                DFS(v, flag);
                count++;
                cout << "\n";
                cout << "group number : " <<count<<"\n";    
            }
        }
      
    }
}
int main()
{
    a[0][deg[0]++] = 1;
    a[0][deg[0]++] = 3;
   //0 a[0][deg[0]++] = 2;
    a[1][deg[1]++] = 4;
   // a[1][deg[1]++] = 7;
   // a[2][deg[2]++] = 0;
    //a[2][deg[2]++] = 5;
    a[3][deg[3]++] = 0;
    a[4][deg[4]++] = 1;
    a[4][deg[4]++] = 5;
    a[5][deg[5]++] = 6;
    a[5][deg[5]++] = 4;
   // a[5][deg[5]++] = 2;
    a[6][deg[6]++] = 5;
   // a[7][deg[7]++] = 1;
    connectedcomp();
}