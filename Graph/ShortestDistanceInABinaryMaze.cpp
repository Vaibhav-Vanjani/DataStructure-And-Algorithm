//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code her
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,source});
        vector<vector<int>> vis(n,vector<int> (m,INT_MAX));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vis[i][j]=INT_MAX;
            }
        }
        
        int ans = INT_MAX;
        vis[source.first][source.second]=INT_MAX;
        
        
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            
            if(destination.first==i && destination.second==j)
            {
                ans = min(dist,ans);
            }
            pq.pop();
            
            if((i-1)>=0 && grid[i-1][j]==1 && vis[i-1][j]>(dist+1))
            {
               vis[i-1][j]=dist+1;
                pq.push({dist+1,{i-1,j}});
            }
            
            if((j-1)>=0 && grid[i][j-1]==1 && vis[i][j-1]>(dist+1))
            {
               vis[i][j-1]=dist+1;
                pq.push({dist+1,{i,j-1}});
            }
            
            if((j+1)<m && grid[i][j+1]==1 && vis[i][j+1]>(dist+1))
            {
                 vis[i][j+1]=dist+1;
                pq.push({dist+1,{i,j+1}});
            }
            
            if((i+1)<n && grid[i+1][j]==1 && vis[i+1][j]>(dist+1))
            {
                vis[i+1][j]=dist+1;
                pq.push({dist+1,{i+1,j}});
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends