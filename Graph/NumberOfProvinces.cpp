//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void bfs(int vis[],int i,vector<vector<int>> &adj)
  {
      queue<int> q;
      q.push(i);
      
      
      while(!q.empty())
      {
          int f = q.front();
          q.pop();
          vis[f]=1;
          
          for(int i=0;i<adj[f].size();i++)
          {
              if(!vis[i] && adj[f][i]!=0)
              {
                  vis[i]=1;
                  q.push(i);
              }
          }
      }
  }
  
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int vis[V+1]={0};
        int provinceCnt = 0;
        
        for(int i=0;i<V;i++)
        {
         if(!vis[i])
         {
             provinceCnt++;
             bfs(vis,i,adj);
         }
        }
        return provinceCnt;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends