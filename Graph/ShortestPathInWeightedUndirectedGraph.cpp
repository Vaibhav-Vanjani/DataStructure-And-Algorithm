//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        // declare min heap and create adjaceny list
        priority_queue<pair<long long int,vector<int>>,vector<pair<long long int,vector<int>>>,
                       greater<pair<long long int,vector<int>>>> pq;
        vector<int> nodes;
        nodes.push_back(1);
        pq.push({0,nodes});
        vector<long long int> ans(100005,LLONG_MAX);
        ans[1]=0;
        vector<int> output;
        
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back({edges[i][2],edges[i][1]});
            adj[edges[i][1]].push_back({edges[i][2],edges[i][0]});
        }
        
        
        
        while(!pq.empty())
        {
            nodes = pq.top().second;
            long long int node = nodes.back();
            
            long long int coverdDistance = pq.top().first;
            pq.pop();
            // return output;
            for(int i=0;i<adj[node].size();i++)
            {
                long long int curr = adj[node][i].second;
                long long int newDistance = adj[node][i].first;
                
               
                if((coverdDistance + newDistance) < ans[curr])
                {
                    nodes.push_back(curr);
                    if(curr == n)
                    {
                        output = nodes;
                    }
                    ans[curr]=coverdDistance + newDistance;
                    pq.push({coverdDistance + newDistance,nodes});
                    nodes.pop_back();
                }
            }
            
             
        }
        
        vector<int> anss = output;
        
        if(anss.size())
        {
            return anss;
        }
        else
        {
            anss.push_back(-1);
            return anss;
        }
    }
};


//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends