//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        
        // {1,2,8,10,11,12,19}
        //        
        
        long long start = 0;
        long long end = n-1;
        
        long long mid=-1;
        long long ans=-1;
        
        while(start<=end)
        {
          mid = start + (end-start)/2;
          
          if(v[mid]<=x)
          {
              ans=mid;
              start=mid+1;
          }
          else
          {
              end=mid-1;
          }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends
------------------------------------------
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        if(n==1)
        {
            if(v[0]<=x)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        
        int start=0;
        int answer=-1;
        int end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(v[mid]<=x)
            {
                answer = mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        
        return answer;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends