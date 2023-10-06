//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int mod=1e9+7;
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        
        int len[n];
        int sum = n;
        for(int i=0;i<n;i++)len[i]=i+1;
        
        long dp[1001][1001];
        memset(dp,-1,sizeof(dp));
    
        for(int i=0;i<sum+1;i++)
        {
           dp[0][i]=-1e7;
        }
        
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=0;
        }
        
         for(int i=1;i<n+1;i++)
        {
           for(int j=1;j<sum+1;j++)
           {
               if(len[i-1]<=j)
               {
                   dp[i][j]=max(dp[i-1][j]%mod,price[i-1] + dp[i][j-len[i-1]]%mod)%mod;
               }
               else
               {
                   dp[i][j]=dp[i-1][j]%mod;
               }
           }
        }
        
        return dp[n][sum]%mod;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends