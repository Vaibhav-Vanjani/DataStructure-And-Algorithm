//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        // Code here
        pair<int,int> source = {0,0};
        int n = grid.size();
        int m = grid[0].size();
        pair<int,int> destination = {n-1,m-1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,source});
        vector<vector<int>> vis(n,vector<int> (m,INT_MAX));
        int ans = INT_MAX;
        vis[source.first][source.second]=0;
        
        
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
            
            if((i-1)>=0 && (vis[i-1][j]>(max(abs(grid[i][j]-grid[i-1][j]),dist))) )
            {
                 vis[i-1][j]=max(abs(grid[i][j]-grid[i-1][j]),dist);
                pq.push({vis[i-1][j],{i-1,j}});
            }
            
            if((j-1)>=0 && vis[i][j-1]>(max(abs(grid[i][j]-grid[i][j-1]),dist)))
            {
            
                vis[i][j-1]=max(abs(grid[i][j]-grid[i][j-1]),dist);
                pq.push({vis[i][j-1],{i,j-1}});
            }
            
            if((j+1)<m && vis[i][j+1]>(max(abs(grid[i][j]-grid[i][j+1]),dist)))
            {
                
               vis[i][j+1]=max(abs(grid[i][j]-grid[i][j+1]),dist);
                pq.push({vis[i][j+1],{i,j+1}});
            }
            
            if((i+1)<n && vis[i+1][j]>(max(abs(grid[i][j]-grid[i+1][j]),dist)))
            {
                 vis[i+1][j]=max(abs(grid[i][j]-grid[i+1][j]),dist);
                pq.push({vis[i+1][j],{i+1,j}});
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends