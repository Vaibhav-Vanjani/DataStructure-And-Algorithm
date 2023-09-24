//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class DisjointSet{
  vector<int> rank,parent,size;
 public:
  DisjointSet(int n)
  {
      rank.resize(n+1,0);
     parent.resize(n+1);
     size.resize(n+1,1);
    //   cout<<"constructor Called"<<endl;
     for(int i=0;i<n;i++)
      {
          parent[i]=i;
      }
  }
  
  int findParent(int node)
  {
      if(parent[node]==node)
      {
          return node;
      }
      
      return parent[node] = findParent(parent[node]);
  }
  
  
  void unionByRank(int u,int v)
  {
      int ulp_u = findParent(u);
      int ulp_v = findParent(v);
      
      if(ulp_u==ulp_v)return;
      
      if(rank[ulp_u] == rank[ulp_v])
      {
          parent[ulp_u] = ulp_v;
          rank[ulp_v]+=1;
      }
      else if(rank[ulp_u] < rank[ulp_v])
          parent[ulp_u]=ulp_v;
      else
           parent[ulp_v]=ulp_u;
      
  }
  
  void unionBySize(int u,int v)
  {
      int ulp_u = findParent(u);
      int ulp_v = findParent(v);
      
      if(ulp_u==ulp_v)return;
      
      if(size[ulp_u] < size[ulp_v])
      {
          parent[ulp_u] = ulp_v;
          size[ulp_v]+=size[ulp_u];
      }
      else 
      {
           parent[ulp_v] = ulp_u;
          size[ulp_u]+=size[ulp_v];
      }
      
  }
};
  

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
    
    int m = edge.size();
    
    DisjointSet ds(n);
    
    if(m<(n-1))
    {
        return -1;
    }
    
    for(int i=0;i<m;i++)
    {
        ds.unionByRank(edge[i][0],edge[i][1]);
    }
    
    int component=0;
     for(int i=0;i<n;i++)
    { 
       if(ds.findParent(i)==i)
       {
           component++;
       }
    }
    
    return component-1;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends