//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
     void bfs(int vis[501][501],int r,int c,int n,int m,vector<vector<char>>& grid)
  {
      if(r<n && c<m && c>=0 && r>=0 && grid[r][c]=='1' && vis[r][c]==0)
      {
          vis[r][c] = 1;
          bfs(vis,r-1,c-1,n,m,grid);
          bfs(vis,r,c-1,n,m,grid);
          bfs(vis,r+1,c-1,n,m,grid);
          bfs(vis,r-1,c+1,n,m,grid);
          bfs(vis,r,c+1,n,m,grid);
          bfs(vis,r+1,c+1,n,m,grid);
          bfs(vis,r-1,c,n,m,grid);
          bfs(vis,r+1,c,n,m,grid);
      }
  }
    
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
       int islandCnt=0;
       int n = grid.size();
       int m = grid[0].size();
       int vis[501][501];
       memset(vis,0,sizeof(vis));
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
                  if(!vis[i][j] && grid[i][j]=='1')
                 {
                     islandCnt++;
                     bfs(vis,i,j,n,m,grid);
                 }            
           }
           
       }
       
        
        return islandCnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends