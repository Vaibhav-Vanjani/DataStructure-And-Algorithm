class Solution {
public:
    int minimumTime(int V, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int> indegree(V+1,0);
        vector<int> adj[V+1];
        for(int i=0;i<relations.size();i++)
        {
            adj[relations[i][0]].push_back(relations[i][1]);
        }

	    for(int i=1;i<(V+1);i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	        {
	            indegree[adj[i][j]]++;
	        }
	    }
	 
	   queue<int> q;
	    for(int i=1;i<(V+1);i++)
	    {
	       if(indegree[i]==0)
	       {
	           q.push(i);
	       }
	   }

    int maxTime[V];
      for(int i=0;i<V;i++)
      {
          maxTime[i]=time[i];
      }     
	   
	   while(!q.empty())
	   {
	       int size = q.size(); 
	       for(int j=0;j<size;j++)
    	    {  
    	        int fr = q.front();
    	        q.pop();
    	        indegree[fr]=-1;
    	        
    	        for(int i=0;i<adj[fr].size();i++)
    	       {
    	           indegree[adj[fr][i]]--;
                   maxTime[adj[fr][i]-1] = max(maxTime[adj[fr][i]-1],maxTime[fr-1]+time[adj[fr][i]-1]);
                    if(indegree[adj[fr][i]]==0)
	                  q.push(adj[fr][i]);
    	       }
    	    }     
   	    }
    int ans = -1;
     for(int i=0;i<V;i++)
     {
         ans=max(ans,maxTime[i]);
     }

     return ans;
        
    }
};