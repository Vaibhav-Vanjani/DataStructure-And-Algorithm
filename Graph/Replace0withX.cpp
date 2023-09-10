//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        
        vector<vector<char>> cpy = mat;
        int u=cpy.size();
        int v=cpy[0].size();
        int vis[501][501]={0};
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(((i==0) or (j==0) or (i==(n-1)) or (j==(m-1))) && cpy[i][j]=='O')
                {
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
             int i = q.front().first;
	        int j = q.front().second;
	       // int cnt = q.front().second;
	        q.pop();
	        
	        if((i-1)>=0 && !vis[i-1][j] && cpy[i-1][j]=='O')
	        {
	           // mat[i-1][j]=0;
	            vis[i-1][j]=1;
	           q.push({i-1,j});
	        }
	        if((j-1)>=0 && !vis[i][j-1] && cpy[i][j-1]=='O')
	        {
	           // mat[i][j-1]=cnt+1;
	            vis[i][j-1]=1;
	            q.push({i,j-1});
	        }
	        if((i+1)<n && !vis[i+1][j] && cpy[i+1][j]=='O')
	        {
	           // cpy[i+1][j]=cnt+1;
	            vis[i+1][j]=1;
	           q.push({i+1,j});
	        }
	        if((j+1)<m && !vis[i][j+1] && cpy[i][j+1]=='O')
	        {
	           // cpy[i][j+1]=cnt+1;
	            vis[i][j+1]=1;
	            q.push({i,j+1});
	        }
        }
        
           for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    cpy[i][j]='X';
                }
            }
        }
        
        return cpy;
        
        
        
        
        
       
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends