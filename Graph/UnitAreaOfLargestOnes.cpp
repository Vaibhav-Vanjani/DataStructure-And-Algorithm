//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet {
public: 
vector<int> rank,parent,sizeR;

DisjointSet(int n) {
parent.resize(n+1);
sizeR.resize(n+1,1);
rank.resize(n+1,0);
for(int i=0;i<=n;i++) parent[i] = i;
}  
 
int findUPar(int node) {
if(node == parent[node]) return node;
return parent[node] = findUPar(parent[node]);
}
  void unionByRank(int u,int v){
     int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
      
  }
void unionBySize(int u,int v) {
int fu = findUPar(u);
int fv = findUPar(v);
 
if(fu == fv) return ;
if(sizeR[fu] < sizeR[fv]) parent[fu] = fv,sizeR[fv]+=sizeR[fu];
else parent[fv] = fu,sizeR[fu]+=sizeR[fv];
}

   
};


bool isValid(vector<vector<int>>& grid,int i,int j,int n,int m)
{
    if(i<n && j<m && i>=0 && j>=0 && grid[i][j]==1)
    {
        return true;
    }
    
    return false;
}


class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);
        bool flag = false;
        // int vis[501][501]={0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    flag=true;
                    for(int k=-1;k<=1;k++)
                    {
                        for(int t=-1;t<=1;t++)
                        {
                            if(k==0 && t==0){}
                            else
                            {
                                int nodekey = i*m + j;
                                int adjkey = (i+k)*m + (j+t);
                                
                                if(isValid(grid,i+k,j+t,n,m))
                                {
                                    if(ds.findUPar(nodekey)!=ds.findUPar(adjkey))
                                    ds.unionBySize(nodekey,adjkey);
                                }
                            }
                        }
                    }
                }
                
            }
        }
        
        int x= ds.sizeR.size();
        int maxi=0;
        for(int i=0;i<(n*m);i++)
        {
            maxi = max(ds.sizeR[i],maxi);
        }
        
        if(!flag)return 0;
        else
        return maxi;
        
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends