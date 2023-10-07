//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  private:
    
// Can we do it using Memoization techniqe of parent problem "Subset with given Sum"??
// The answer is no because recursive technique always fills the cells in 
// the table which are neccessary for solving the bigger problem, it will not 
// always fill the whole matrix but here we need the whole (n-1)th row to be filled
// to do partitioning hence we can do it using tabulation only.
// for filling the 2d dp array donot fill it with memoization technique

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	  int sum = 0;
	 for(int i=0;i<n;i++){sum+=arr[i];}   
// 	 return sum;
	 sort(arr,arr+n);
	 vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
	 for(int i=0;i<=n;i++)dp[i][0]=1;
    
    for(int i=1;i<=n;i++)
    {
         for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
	
	 int mini = INT_MAX;
	 for(int i=0;i<(sum+1);i++)
	 {
	    if(dp[n][i]==1)
	    {
	        mini = min(mini,abs(sum-(2*i)));
	    }
	 }
	 return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends