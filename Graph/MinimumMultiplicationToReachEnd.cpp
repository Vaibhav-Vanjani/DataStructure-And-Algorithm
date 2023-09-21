//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        if(start==end)return 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,start});
        int n = arr.size();
        int vis[100001] = {0};
       vis[start]=1;
        
        // return 2;
        while(!q.empty())
        {
            int key = q.top().first;
            int node = q.top().second;
            q.pop();
            
            if(node == end)
            return key;
            
            // if(node>end)continue;
            
            for(int i=0;i<n;i++)
            {
                if(!vis[(node*arr[i])%100000])
                {
                    vis[(node*arr[i])%100000]=1;
                    
                      if(((node*arr[i])%100000) == end)
                      return key+1;
                    q.push({key+1,(node*arr[i])%100000});
                }
            }
            
            
        }
        return -1;
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends