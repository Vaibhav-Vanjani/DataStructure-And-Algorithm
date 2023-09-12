//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int k,stack<int> &s,int vis[],vector<int> adj[])
	{
	    for(int i=0;i<adj[k].size();i++)
	    {
	        if(!vis[adj[k][i]])
	        {
	            vis[adj[k][i]]=1;
	            dfs(adj[k][i],s,vis,adj);
	           // s.push(adj[k][i]);
	        }
	    }
	    
	    if(s.empty() or k!=s.top())
	    {
	        s.push(k);
	        vis[k]=1;
	    } 
	   
	    
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> s;
	    vector<int> ans;
	    int vis[V]={0};
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i]){dfs(i,s,vis,adj);}
	    }
	    
	    while(!s.empty())
	    {
	        int a = s.top();
	        ans.push_back(a);
	        s.pop();
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends