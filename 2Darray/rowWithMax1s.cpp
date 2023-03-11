//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    
	    int x = arr.size();
	    int ans =-1;
	    int res ;
	    int ones = 0 ;
	    for(int i=0;i<n;i++)
	    {
	        int start=0;
	        int end = m-1;
	        
	        vector<int> v = arr[i];
	        int size = v.size();
	        res = size;
	        
	        while(start<=end)
	        {
	            int mid = start +(end-start)/2 ;
	            
	            if(v[mid] == 1)
	            {
	                res = mid ;
	                end = mid - 1;
	            }
	            else
	            {
	                start = mid+1;
	            }
	        }
	        
	        if(ones < (size - res) )
	        {
	            ans = i;
	            ones = size - res;
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
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends