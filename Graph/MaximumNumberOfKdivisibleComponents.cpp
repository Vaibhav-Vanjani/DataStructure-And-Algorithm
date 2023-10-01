class Solution {
private
    bool dfs(int z,int n, vectorint adj[], vectorint& value, int k,int vis[])
    {     
      int sum=0;
      sum+=value[z];
      vis[z]=1;
        
        for(int i=0;iadj[z].size();i++)
        {
            if(!vis[adj[z][i]])
            {
                vis[adj[z][i]]=1;
                
                bool val = dfs(adj[z][i],n,adj,value,k,vis);
                if(val)value[adj[z][i]]=0;
                
                 sum+=value[adj[z][i]];
            }
        } 
      
        if(sum%k==0)
       {    
             value[z]=0;
            return true;
       }
        else 
        {  
            value[z]=sum;
            return false;
        }     
    }
    
public    
    int maxKDivisibleComponents(int n, vectorvectorint& edges, vectorint& values, int k) {
        
        vectorint adj[n];
        
        for(int i=0;iedges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
        }
        
        int vis[n];
        memset(vis,0,sizeof(vis));
        int yes=0;
        
        for(int i=0;in;i++)
        bool f = dfs(i,n,adj,values,k,vis);
        
        
        int cnt=0;
            for(int i=0;in;i++)
            { 
                if(values[i]==0)
                cnt++;
            }
        
        return cnt;
    }
};