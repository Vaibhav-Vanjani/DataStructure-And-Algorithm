//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet {
public: 
vector<int> rank,parent,size;

DisjointSet(int n) {
parent.resize(n+1);
size.resize(n+1,1);
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
if(size[fu] < size[fv]) parent[fu] = fv,size[fv]+=size[fu];
else parent[fv] = fu,size[fu]+=size[fv];
}

   
};


class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        // 0 1 0 1 0
        // 1 1 1 1 0
        
        //01 11 12
        
        
        // 11 01
        
        
        
        vector<vector<int>> l(n,vector<int> (m,0));
        int component=0;
        vector<int> ans;
        DisjointSet ds(n*m);
        for(int i=0;i<operators.size();i++)
        {
            int u = operators[i][0];
            int v = operators[i][1];
        
            
         
           if(!l[u][v]) 
           { 
               
           l[u][v]=1;
           
           
           if((u-1)>=0 && l[u-1][v]==1)
           {
               int nodekey = u*m+v;
               int adjkey = (u-1)*m + v;
               if(ds.findUPar(nodekey)!=ds.findUPar(adjkey))
               {
                   component--;
                   ds.unionByRank(nodekey,adjkey);
               }
           }
          
           if((v-1)>=0 && l[u][v-1]==1)
           { 
               int nodekey = u*m+v;
               int adjkey = u*m + (v-1);
               if(ds.findUPar(nodekey)!=ds.findUPar(adjkey))
               {
                   component--;
                   ds.unionByRank(nodekey,adjkey);
               }
           }
          
           if((u+1)<n && l[u+1][v]==1)
           {
               int nodekey = u*m+v;
               int adjkey = (u+1)*m + v;
               if(ds.findUPar(nodekey)!=ds.findUPar(adjkey))
               {
                   component--;
                   ds.unionByRank(nodekey,adjkey);
               }
           }
           
           if((v+1)<m && l[u][v+1]==1)
           {
               int nodekey = u*m+v;
               int adjkey = u*m +(v+1);
               if(ds.findUPar(nodekey)!=ds.findUPar(adjkey))
               {
                   component--;
                   ds.unionByRank(nodekey,adjkey);
               }
           }
           
           component++;
           }
           
            ans.push_back(component);
           
           
          
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends