// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
   
    //store in matrix
    int n;
    int m;
    
    cin>>n>>m;
    int mat[n+1][m+1];
    memset(mat,0,sizeof(mat));
    
    for(int i=0;i<m;i++)
    {
        int u;
        int v;
        cin>>u>>v;
        mat[u][v]=1;
        mat[v][u]=1;
    }
    
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
          cout<<mat[i][j];
        }
        cout<<endl;
    }
    
// 5 6
// 1 2
// 1 3
// 3 4
// 4 2
// 2 5
// 4 5

output->
0000000
0011000
0100110
0100100
0011010
0010100
    
    
    
    
    
    return 0;
}