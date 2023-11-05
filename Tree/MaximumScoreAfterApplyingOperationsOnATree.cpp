class Solution {
public:

    long long dfs(int node,vector<int> &values,vector<int> adj[],int vis[])
    {
        if(adj[node].size()==1 && vis[adj[node][0]])return (long long)values[node];

        long long sum = 0;
        for(auto x:adj[node])
        {
            if(!vis[x])
            {
                vis[x]=1;
                long long temp = min(dfs(x,values,adj,vis),(long long)values[x]);
                sum+=temp;
            }
        }
        return min((long long)values[node],sum);
    }


    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<int> adj[n];
        int vis[n];
        long long sum=0;
        for(int i=0;i<n;i++){vis[i]=0;sum+=values[i];}

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vis[0]=1;
        return sum-dfs(0,values,adj,vis);
    }
};