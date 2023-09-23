//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
                     
        //create adjacency matrix  
        int matrix[n][n];
        memset(matrix,-1,sizeof(matrix));
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            matrix[u][v]=wt;
            matrix[v][u]=wt;
    
        }
    
	    for(int via=0;via<n;via++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                if(i==j)matrix[i][j]=0;
	                
	                if((matrix[i][via]<0) or (matrix[via][j]<0))
	                 {}
	                else if(matrix[i][j]==-1 && (matrix[i][via]+matrix[via][j]>=0))
	                 matrix[i][j] = matrix[i][via]+matrix[via][j];
	                else 
	                 matrix[i][j] = min(matrix[i][via]+matrix[via][j],matrix[i][j]);
	            }
	        }
	    }
	    
	    int ans = -1;
	    int prev = INT_MAX;
	    int cnt=0;
	    
	   // return n;
	    
	     for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	             if(matrix[i][j]==-1 or matrix[i][j]==0){}
	             else{
	                if((matrix[i][j]<=distanceThreshold))
	                {
	                    cnt++;
	                }
	               }
	            }
	       if(cnt<=prev)
	       {
	           prev = cnt;
	           ans=i;
	       }
	        cnt=0;
	        }
	    return ans;
	    
	    
	    
	    
 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends