//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
           // Code here
           
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<pair<int,int>> adj[101];
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        pq.push({K,{src,0}});
        vector<int> ans(101,INT_MAX);
        
        while(!pq.empty())
        {
            int k = pq.top().first;
            int node = pq.top().second.first;
            int sum = pq.top().second.second;
            
            pq.pop();
            
            for(int i=0;i<adj[node].size();i++)
            {
                if(k>=0 && ((sum+adj[node][i].second) < ans[adj[node][i].first]))
                {
                    k-=1;
                    
                    if((adj[node][i].first==dst) or (k>=0))
                    {
                        ans[adj[node][i].first]=sum+adj[node][i].second;
                        pq.push({k,{adj[node][i].first,sum+adj[node][i].second}});
                    }
                    
                    k+=1;
                }
            }
            
        }
        return ans[dst]==INT_MAX ? -1 : ans[dst];
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends