//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
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


class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
       
       
    //   0 1 2
    //   3
    //   4
    //   5
      
    //   0 1 2
    int size = 2e4+1;
    DisjointSet ds(size);
      
      int maxCol = 0;
      int maxRow = 0;
      for(int i=0;i<n;i++)
      {
          maxCol = max(maxCol,stones[i][1]);
      }
      
      for(int i=0;i<n;i++)
      {
          int u = stones[i][0] + maxCol + 1;
          maxRow = max(maxRow,u);
          int v = stones[i][1];
          
          if(ds.findUPar(u)!=ds.findUPar(v))
          {
              ds.unionBySize(u,v);
          }
      }
      
      
      int ans = 0;
      for(int i=0;i<=maxRow;i++)
      {
          if(i==ds.parent[i] && ds.sizeR[i]>2)
          {
              ans+= (ds.sizeR[i]-2);
          }
      }
      return ans;
      
      
      
      
     
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends