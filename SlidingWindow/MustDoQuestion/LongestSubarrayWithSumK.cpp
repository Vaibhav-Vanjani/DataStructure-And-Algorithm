//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the functi        // Complete the function
       unordered_map<int,int> mp ;
        int sum =0; 
        int maxi =0;

       
        for(int i = 0 ; i<N ;i++)
        {
            sum+=A[i];
           
            
            if(!mp[sum])
            mp[sum]=i;
           
            if(sum==K)
            {maxi=max(maxi,(i+1));}
            else if(mp.find(sum-K)!=mp.end())
            {
                maxi=max(maxi,i-mp[sum-K]);
            }
            
            
//        1 49  -5  5 -5 20    
                         
        }
        return maxi;
    
    
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends