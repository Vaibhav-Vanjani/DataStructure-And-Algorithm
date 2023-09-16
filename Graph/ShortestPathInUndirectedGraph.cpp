//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
   void dfs(int k, vector<int> adj[],int sum,int dp[],int vis[])
    {
       if(!vis[k])
       {
            vis[k]=1;
            for(int i=0;i<adj[k].size();i++)
            {
                sum+=1;
                
                int fr = adj[k][i];
                dp[fr] = min(sum,dp[fr]);
                
                if(dp[fr] == sum)
                dfs(fr,adj,sum,dp,vis);
                
                sum-=1;
            }
            vis[k]=0;
       }
    }
  
  
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        int u=edges.size();
        int v = edges[0].size();
        
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int dp[N+1];
        for(int i=0;i<=N;i++)
        dp[i]=INT_MAX;
        
        int vis[N+1]={0};
        
        int sum=0;
        
                dfs(src,adj,sum,dp,vis);
    
        
        
        dp[src]=0;
        for(int i=0;i<N;i++)
        {
            if(dp[i]==INT_MAX)
            dp[i]=-1;
        }
        
        vector<int> ans;
        for(int i=0;i<N;i++)
        {
            ans.push_back(dp[i]);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends