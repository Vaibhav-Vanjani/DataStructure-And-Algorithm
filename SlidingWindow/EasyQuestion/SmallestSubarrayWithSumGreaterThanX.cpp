//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int start=0;
        int end=0;
        int sum=0;
        int minimumLength=INT_MAX;
        
        while(end<n)
        {
            sum+=arr[end];
            
            if(sum<=x)end++;
            else if(sum>x)
            {
                while(sum>x)
                {
                    minimumLength=min(minimumLength,end-start+1);
                    sum-=arr[start];
                    start++;
                }
                end++;
            }
        }
        if(minimumLength==INT_MAX)return 0;
        return minimumLength;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends