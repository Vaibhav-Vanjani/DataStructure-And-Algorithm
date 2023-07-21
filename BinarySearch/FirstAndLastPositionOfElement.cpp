class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
    //   [5, 7, 7, 8, 8, 10]

    int start = 0;
    int end = nums.size()-1;

    int firstIndex = -1;
    int lastIndex = -1;

    // finding first index of target
    while(start<=end)
    {
        int mid = start + (end-start)/2;

        if(nums[mid] == target)
        {
            firstIndex = mid;
            end = mid-1;
        }
        else if (nums[mid] > target)
        {
            end=mid-1;
        }
        else
        {
            start = mid+1;
        }
    }

    //  vector<int> ans ;
    // ans.push_back(firstIndex);
    // ans.push_back(lastIndex);
    // return ans;

    start = 0;
    end = nums.size()-1;

    while(start<=end)
    {
        int mid = start + (end-start)/2;

        if(nums[mid] == target)
        {
            lastIndex = mid;
            start = mid+1;
        }
        else if (nums[mid] > target)
        {
            end=mid-1;
        }
        else
        {
            start = mid+1;
        }
    }

    vector<int> ans ;
    ans.push_back(firstIndex);
    ans.push_back(lastIndex);
    return ans;
    }
};

---------------------------------------

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        if(v.size()==1)
        {
            if(x==v[0])
            {
                return {0,0};
            }
            else
            {
                return {-1,-1};
            }
        }
          // checking the first occurence
        long long start =0 ;
        long long end = v.size()-1;
        long long firstOccurence=-1;
        while(start<=end)
        {
            long long mid = start + (end-start)/2;
            
            if(v[mid]==x)
            {
                firstOccurence = mid;
                end=mid-1;
            }
            else if(v[mid]>x)
            {
             end=mid-1;   
            }
            else
            {
                start=mid+1;
            }
        }
        start=0;
        end=v.size()-1;
        long long lastOccurence=-1;
        while(start<=end)
        {
            long long mid=start + (end-start)/2;
            if(v[mid]==x)
            {
                lastOccurence = mid;
                start=mid+1;
            }
            else if(v[mid]<x)
            {
                start=mid+1;    
            }
            else
            {
                end=mid-1;
            }
        }
        
        return {firstOccurence,lastOccurence};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends