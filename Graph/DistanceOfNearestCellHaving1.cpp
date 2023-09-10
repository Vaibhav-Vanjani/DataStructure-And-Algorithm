//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	   
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> cpy = grid;
	    queue<pair<pair<int,int>,int>> q;
	    int vis[501][501]={0};
	    int u = cpy.size();
	    int v = cpy[0].size();
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
    	    {
    	        if(grid[i][j]==1)
    	       {
    	           cpy[i][j]=0;
    	           vis[i][j]=1;
    	           q.push({{i,j},0});
    	       }
    	    }
	    }
	    
	    while(!q.empty())
	    {
	        int i = q.front().first.first;
	        int j = q.front().first.second;
	        int cnt = q.front().second;
	        
	        q.pop();
	        
	        if((i-1)>=0 && !vis[i-1][j] && !grid[i-1][j])
	        {
	            cpy[i-1][j]=cnt+1;
	            vis[i-1][j]=1;
	            q.push({{i-1,j},cnt+1});
	        }
	        if((j-1)>=0 && !vis[i][j-1] && !grid[i][j-1])
	        {
	            cpy[i][j-1]=cnt+1;
	            vis[i][j-1]=1;
	            q.push({{i,j-1},cnt+1});
	        }
	        if((i+1)<n && !vis[i+1][j] && !grid[i+1][j])
	        {
	            cpy[i+1][j]=cnt+1;
	            vis[i+1][j]=1;
	            q.push({{i+1,j},cnt+1});
	        }
	        if((j+1)<m && !vis[i][j+1] && !grid[i][j+1])
	        {
	            cpy[i][j+1]=cnt+1;
	            vis[i][j+1]=1;
	            q.push({{i,j+1},cnt+1});
	        }
	    }
	    
	    return cpy;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends