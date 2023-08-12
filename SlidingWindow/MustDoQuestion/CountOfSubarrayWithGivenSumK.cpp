class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count=0;
        long sum=0;
        unordered_map<int,int> mp;
        int n =nums.size();
        long K=k;


        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum == K)
            count++;

            if(mp.find(sum-K)!=mp.end())
            {
                count+=mp[sum-K];
            }
             mp[sum]++;
        }
        return count;
    }
};


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to count the number of subarrays which adds to the given sum.
    int subArraySum(int arr[], int n, int k)
    {
        //Your code here
        
        int count=0;
        unordered_map<int,int> mp;
        int sum=0;
        int N=n;
        
        
        // for 0 0 0 0 0 0 0
        // k =0 
        // mp[sum] is at the bottom
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
              
            if(sum==k)
            {
                count+=1;
            }
            
             if(mp.find(sum-k)!=mp.end())
            {
                count+=mp[sum-k];
            }
            
            mp[sum]++;
        }
        return count;
       
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    Solution obj;
	    cout<<obj.subArraySum(arr, n, sum)<<endl;
	}
	return 0;
}
// } Driver Code Ends