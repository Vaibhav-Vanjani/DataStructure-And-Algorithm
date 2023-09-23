//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        long long sum =0;
        pair<long long,pair<int,int>> weightNodeParent = {0,{0,-1}};
        priority_queue< pair<long long,pair<int,int>>,vector< pair<long long,
                        pair<int,int>>>,greater< pair<long long,pair<int,int>>>> pq;
        
        pq.push(weightNodeParent);
        int vis[1001]={0};
        
        while(!pq.empty())
        {
             pair<int,pair<int,int>> minimumPair = pq.top();
             long long currWeight = minimumPair.first;
             int currNode = minimumPair.second.first;
             int currParent = minimumPair.second.second;
             pq.pop();
             
             if(vis[currNode])continue;
             
             if((currParent != -1) && !vis[currNode])sum+=currWeight;
             vis[currNode]=1;
             
             for(int i=0;i<adj[currNode].size();i++)
             {
                 int childNode = adj[currNode][i][0];
                 long long childWt = adj[currNode][i][1];
                 
                 if(!vis[childNode])
                 {
                     pq.push({childWt,{childNode,currNode}});
                 }
             }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends