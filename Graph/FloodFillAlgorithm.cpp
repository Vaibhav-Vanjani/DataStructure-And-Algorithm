//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

     void bfs(int val,int vis[101][101],int r,int c,int n,int m,vector<vector<int>>& grid,int newColor)
  {
      if(r<n && c<m && c>=0 && r>=0 && (grid[r][c]==val)  && vis[r][c]==0)
      {
          val = grid[r][c];
          grid[r][c] = newColor;
          vis[r][c]=1;
          bfs(val,vis,r,c-1,n,m,grid,newColor);
          bfs(val,vis,r,c+1,n,m,grid,newColor);
          bfs(val,vis,r-1,c,n,m,grid,newColor);
          bfs(val,vis,r+1,c,n,m,grid,newColor);
      }
  }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        
        
       int islandCnt=0;
       int n = image.size();
       int m = image[0].size();
       int vis[101][101];
       memset(vis,0,sizeof(vis));
       
        int val=image[sr][sc];
        bfs(val,vis,sr,sc,n,m,image,newColor);
       
        
        return image;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends