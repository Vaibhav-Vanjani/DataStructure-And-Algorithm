//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfsForReverseEdges(int vis[],vector<vector<int>>& radj,int k)
	{
	     vis[k]=1;
	 	  for(int i=0;i<radj[k].size();i++)
    	  {
    	      if(!vis[radj[k][i]])
    	      dfsForReverseEdges(vis,radj,radj[k][i]);
    	  }
	}
	
	
	void dfsAndStoreInStack(int k,stack<int> &s,vector<vector<int>>& adj,int vis[])
	{
	    vis[k]=1;
	 	  for(int i=0;i<adj[k].size();i++)
    	  {
    	       if(!vis[adj[k][i]])
	            {
        	      vis[adj[k][i]]=1;
        	      dfsAndStoreInStack(adj[k][i],s,adj,vis);
        	      s.push(adj[k][i]);
    	         }
    	  }
    	  s.push(k);
	}
	
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> s;
        int vis[V]={0};
        for(int i=0;i<V;i++)
       {
           if(!vis[i])
           dfsAndStoreInStack(i,s,adj,vis);
        }
        
        
        vector<vector<int>> reverseAdj(5001);
        for(int i=0;i<V;i++)
        {
             for(int j=0;j<adj[i].size();j++)
             {
                reverseAdj[adj[i][j]].push_back(i); 
             }
        }
        
        int visForReverseEdges[5001]={0};
        int cnt=0;
        while(!s.empty())
        {
            int topEle = s.top();
            if(visForReverseEdges[topEle]==0)
            {
                cnt++;
                dfsForReverseEdges(visForReverseEdges,reverseAdj,topEle);
            }
            s.pop();
        }
        return cnt;
        
        
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends