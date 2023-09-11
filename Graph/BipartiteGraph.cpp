//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int k,vector<int> adj[],int vis[],int cnt,int parent)
    {
        
          
        vis[k]=cnt;
        cnt = cnt == 2 ? 1:2;
        
        for(int i=0;i<adj[k].size();i++)
        {
          
            parent = k;
            // cnt = cnt==2 ? 1:2;
            if(!vis[adj[k][i]])
            {
                vis[adj[k][i]]=cnt;
                  if(!dfs(adj[k][i],adj,vis,cnt,parent))
                    return false;
            }
            else
            {
                if(parent!=-1 && vis[adj[k][i]]==vis[parent])
                return false;
            }
            
          
        }
        return true;
    }
    


	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	     int vis[100001]={0};
	   for(int i=0;i<V;i++)
	   {
	       if(!vis[i] && !dfs(i,adj,vis,2,-1))
	       {
	           return false;
	       }
	   }
	    
	    return true;
	    
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends