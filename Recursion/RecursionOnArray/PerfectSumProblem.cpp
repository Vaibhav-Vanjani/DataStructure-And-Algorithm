//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int mod = 1e9+7;
class Solution{
    
    int helper(int i,int arr[],int n,int sum,int cnt,int dp[1001][1001])
    {
        if(i==n and sum==0)return 1;
        if(i==n and sum!=0)return 0;
        
        if(dp[i][sum]!=-1)return dp[i][sum];
        
        if(arr[i]<=sum)   
      { 
         int l = helper(i+1,arr,n,sum,cnt,dp)%mod;
        int r = helper(i+1,arr,n,sum-arr[i],cnt,dp)%mod;
        return dp[i][sum] = (l+r)%mod;
      }
      else
      {
          return  dp[i][sum] = helper(i+1,arr,n,sum,cnt,dp)%mod;;
      }
        
        
        
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            if(arr[i]>sum){n=i;break;}
        }
        int dp[1001][1001];
    memset(dp,-1,sizeof(dp));
    
        return helper(0,arr,n,sum,0,dp)%mod;
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends