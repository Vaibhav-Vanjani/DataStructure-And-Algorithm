//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
  



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	bool static comp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
	{
	    if(a.first<b.first)
	    return true;
	    
	    return false;
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> storeswtAndEdge;
        for(int i=0;i<V;i++)
        {
            int node1 = i;
            for(int j=0;j<adj[i].size();j++)
            {
                int wt = adj[i][j][1];
                int node2 = adj[i][j][0];
                storeswtAndEdge.push_back({wt,{node1,node2}});
            }
        }
        
        sort(storeswtAndEdge.begin(),storeswtAndEdge.end(),comp);
        DisjointSet ds(V);
        int sum=0;
        // return sum;
        for(int i=0;i<storeswtAndEdge.size();i++)
        {
            int wt = storeswtAndEdge[i].first;
            int node1 = storeswtAndEdge[i].second.first;
            int node2 = storeswtAndEdge[i].second.second;
            
            if(ds.findParent(node1)!=ds.findParent(node2))
            {
                sum+=wt;
                ds.unionByRank(node1,node2);
            }
        }
        
        return sum;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends