//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class DisjointSet{
  vector<int> rank,parent,size;
 public:
  DisjointSet(int n)
  {
      rank.resize(n+1,0);
     parent.resize(n+1);
     size.resize(n+1,1);
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
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
       
        DisjointSet ds(V);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                if(adj[i][j]==1)
                {
                   ds.unionByRank(i,j); 
                }
            }
        }
        
        int component=0;
        for(int i=0;i<V;i++)
        {
            if(ds.findParent(i)==i)
            component++;
        }
        
        return component;
            
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends