class Solution {
private:
    void dfs(int k,int parent,int &j,int low[],int time[],vector<int> ans,vector<vector<int>> &output,int vis[],vector<int> adj[])
    {
        vis[k]=1;
        time[k]=low[k]=++j;

        for(int i=0;i<adj[k].size();i++)
        {
            if(!vis[adj[k][i]])
            {
                dfs(adj[k][i],k,j,low,time,ans,output,vis,adj);

                if(low[adj[k][i]]>time[k])
                {
                ans.push_back(adj[k][i]);
                ans.push_back(k);
                output.push_back(ans);
                ans.clear();
                }

            }

            if(adj[k][i] != parent)
                low[k] = min(low[adj[k][i]],low[k]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int j=-1;
        vector<vector<int>> output;
        int low[n],time[n];
        memset(low,1e8,sizeof(low));
        memset(time,1e8,sizeof(time));
        vector<int> ans;
        int vis[n];
        memset(vis,0,sizeof(vis));

        dfs(0,-1,j,low,time,ans,output,vis,adj);
        return output;
    }
};