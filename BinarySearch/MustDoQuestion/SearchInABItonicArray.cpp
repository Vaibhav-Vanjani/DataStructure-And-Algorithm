//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
   // Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int get_Max_From_bitonic_Array( vector<int> nums)
{
    int n = nums.size();
    
    int start =0;
    int end =n-1;
    
    if(!end)return nums[end];
    int mid = nums[0];
    
    while(start<=end)
    {
        mid = start + (end-start)/2;

            if( (mid>0) && (mid<n-1)&&(nums[mid]>nums[mid-1]) && (nums[mid]>nums[mid+1]) )
            return nums[mid];
            else
            {
                if(mid==0)
                {
                    if(nums[mid]>nums[mid+1])
                    return nums[mid];
                    else
                    start=mid+1;
                }
                else if(mid==(n-1))
                {
                    if(nums[mid]>nums[mid-1])
                    return nums[mid];
                    else
                    end=mid-1;
                }
                else if(nums[mid]<nums[mid-1])
                end=mid-1;
                else if(nums[mid]<nums[mid+1])
                start=mid+1;
            }
    }
    return mid;
}
};
