//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
  
  bool isValid(long long mid,int arr[],int k,int n)
  {
      int painter=1;
      long long sum=0;
      for(int i=0;i<n;i++)
      { 
           sum+=arr[i];
           if(sum>mid)
           {
               painter++;
               sum=arr[i];
           }
           
           if(painter>k or arr[i]>mid)
           return false;
           
      }
      
      if(sum>mid)return false;
      
      return true;
      
  }
  
  
  
  
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
      
        long long sum=0;
        for(long long i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        
        
        long long start = 1;
        long long end =sum;
        long long res=-1;
      while(start<=end)
      {
          
          long long mid=start+(end-start)/2;
          
          if(isValid(mid,arr,k,n))
          {
              res=mid;
              end=mid-1;
          }
          else
          {
              start=mid+1;
          }
          
      }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends