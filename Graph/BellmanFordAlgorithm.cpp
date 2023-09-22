//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
    
        vector<int> ans(V,1e8);
        ans[S]=0;
        
        for(int i=0;i<V;i++)
        {
           for(int i=0;i<edges.size();i++)
          {
              int dist = ans[edges[i][0]];
              int wt =  edges[i][2];
              int dest = ans[edges[i][1]];
              
              if(dist==1e8){}
              else if((dist+wt)<dest)
              {
                  ans[edges[i][1]]=dist+wt;
              }
          }
        }
        
        vector<int> checkForNegitiveCycle=ans;
        int size = checkForNegitiveCycle.size();
        
          for(int i=0;i<edges.size();i++)
          {
              int dist = ans[edges[i][0]];
              int wt =  edges[i][2];
              int dest = ans[edges[i][1]];
              
              if(dist==1e8){}
              else if((dist+wt)<dest)
              {
                  ans[edges[i][1]]=dist+wt;
              }
          }
            
        vector<int> negitiveOnes(1,-1);    
        for(int i=0;i<V;i++)
        {
            if(checkForNegitiveCycle[i]!=ans[i])return negitiveOnes;
        }
        
        return ans;
        
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends