class Solution {
public:


    bool dfs(int k,vector<int> adj[],int vis[],int dp[])
    {
        if(dp[k]!=-1)return dp[k];
        for(int i=0;i<adj[k].size();i++)
        {
            if(!vis[adj[k][i]]){
                vis[adj[k][i]]=1;
                if(dfs(adj[k][i],adj,vis,dp))return dp[adj[k][i]]=true;
                vis[adj[k][i]]=0;
            }
            else
            return dp[adj[k][i]]=true;
        }
        return dp[k] = false;
    }



    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        int vis[numCourses];
        int dp[numCourses];
        for(int i=0;i<numCourses;i++)
       { vis[i]=0;
         dp[i]=-1;
         }
        


        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,dp))
                return false;
            }
        }

        return true;
      
    }
};class Solution {
public:


    bool dfs(int k,vector<int> adj[],int vis[],int dp[])
    {
        if(dp[k]!=-1)return dp[k];
        for(int i=0;i<adj[k].size();i++)
        {
            if(!vis[adj[k][i]]){
                vis[adj[k][i]]=1;
                if(dfs(adj[k][i],adj,vis,dp))return dp[adj[k][i]]=true;
                vis[adj[k][i]]=0;
            }
            else
            return dp[adj[k][i]]=true;
        }
        return dp[k] = false;
    }



    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        int vis[numCourses];
        int dp[numCourses];
        for(int i=0;i<numCourses;i++)
       { vis[i]=0;
         dp[i]=-1;
         }
        


        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,dp))
                return false;
            }
        }

        return true;
      
    }
};