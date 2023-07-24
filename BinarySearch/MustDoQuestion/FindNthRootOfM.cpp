// cout<< (3*(3.3) == 9.9) //op-> 0
// cout<< ( ((float)3*(3.3)) == 9.9) //op-> 1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
	    // Code here.
class Solution{
	public:
	
	bool isValid(int mid ,int n,int m)
	{
	     float a = log2(m);
         float b = (n*log2(mid));
	    
	    return b <= a;
	}
	
	int NthRoot(int n, int m)
	{
	    // Code here.
	   int start =1;
	   int end = m;
	   
	   int ans=-1;
	   while(start<=end)
	   {
	       int mid = start + (end-start)/2;
	       
	       if(isValid(mid,n,m))
	       {
	           ans = mid ;
	           start=mid+1;
	       }
	       else
	       end=mid-1;
	   }
	   
	      float a = log2(m);
          float b = (n*log2(ans));
    
       if(a==b)
	   return ans;
	   else 
	   return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends