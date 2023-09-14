class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          
          int V=numCourses;
          vector<int> indegree(V,0);
          int n = prerequisites.size();
          vector<int> adj[V];
	    for(int i=0;i<n;i++)
	    {
	       indegree[prerequisites[i][0]]++;
	    }

         for(int i=0;i<n;i++)
	    {
	       adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	    }
	    
	   // bfs 
	   queue<int> q;
	   vector<int> ans;
	   
	    for(int i=0;i<V;i++)
	   {
	       if(indegree[i]==0)
	       {
	           q.push(i);
	       }
	   }

        if(q.empty())return ans;
	       
	   
	   while(!q.empty())
	   {
	       int size = q.size();
	       
	       for(int j=0;j<size;j++)
    	    {  
    	        int fr = q.front();
    	        q.pop();
    	        ans.push_back(fr);
    	        indegree[fr]=-1;
    	        
    	        for(int i=0;i<adj[fr].size();i++)
    	       {
    	           indegree[adj[fr][i]]--;
    	       }
    	    }
    	    
    for(int i=0;i<V;i++)
	   {
	       if(indegree[i]==0)
	       {
	           q.push(i);
	       }
	   }    
	   }

      

         for(int i=0;i<V;i++)
	   {
	       if(indegree[i]!=-1)
	       {
              vector<int> temp;
              return temp;
	       }
	   }    

	   
	   //cout<<ans.size();
	   return ans;
	   
    }
};