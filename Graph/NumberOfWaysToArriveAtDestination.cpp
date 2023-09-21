//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& edges) {
        // code here
        
        int mod = 1e9 + 7;
        vector<pair<int,int>> adj[201];
        int actual = INT_MAX;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        multiset<pair<long long,long long>> pq;
        pq.insert({0,0});
        vector<long long> ans(201,1e12);
        ans[0]=0;
        int cnt=0;
        vector<long long> ways(201,0);
        ways[0]=1;
        
        while(!pq.empty())
        {
            auto it = *pq.begin();
            long long earlierTime = it.first;
            long long node = it.second;
            pq.erase(pq.begin());
            
            for(int i=0;i<adj[node].size();i++)
            {
                long long currTime = adj[node][i].second;
                int curr = adj[node][i].first;
                
              if( (earlierTime+currTime)<ans[curr] )
              {
                  ways[curr]=ways[node]%mod;
                  ans[curr] = (earlierTime+currTime);
                  pq.insert({ans[curr],curr});
              }
              else if((earlierTime+currTime)==ans[curr])
              {
                  ways[curr]=(ways[curr]+ways[node])%(mod);
              }
            }
            
        }
        
        return ways[n-1]%(mod);
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends