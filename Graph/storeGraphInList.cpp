// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
   
    //store in matrix
    int n;
    int m;
    
    cin>>n>>m;
    vector<int> adj[m+1];
    
    for(int i=0;i<m;i++)
    {
        int u;
        int v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    n = m+1;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" :";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j];
        }
        cout<<endl;
    }
    
// input->    
// 5 6
// 1 2
// 1 3
// 3 4
// 4 2
// 2 5
// 4 5
 
// output-> 
// 0 :
// 1 :23
// 2 :145
// 3 :14
// 4 :325
// 5 :24
// 6 :
    
    
    
    
    
    return 0;
}