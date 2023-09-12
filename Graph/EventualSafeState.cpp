//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool dfs(int k,vector<int> adj[],int vis[],int dp[])
    {
        vis[k]=1;
        
        if(dp[k]!=-1)return dp[k];
        
        for(int i=0;i<adj[k].size();i++)
        {
            if(!vis[adj[k][i]])
            {
                vis[adj[k][i]]=1;
                if(dfs(adj[k][i],adj,vis,dp))
                return dp[adj[k][i]] = true;
                vis[adj[k][i]]=0;
                
            }
            else
            {
                return dp[adj[k][i]] = true;
            }
        }
        return dp[k] = false;
    }
  
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
          int dp[V+1];
          vector<int> ans;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<V;i++)
        {
            int vis[V]={0};
            if(!vis[i] && dfs(i,adj,vis,dp))
            {}
        }
        
        for(int i=0;i<V;i++)
        {
            if(dp[i]==0)
            {
                ans.push_back(i);
            }
        }
        
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends