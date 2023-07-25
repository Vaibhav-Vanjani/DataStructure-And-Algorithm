class Solution {
public:

    bool isValid(int mid,vector<int> nums ,int k)
    {
        long long sum =0;
        int count_k = 1;
        int n =nums.size();
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            if(sum>mid)
            {
                sum=nums[i];
                count_k++;
            }

            if(count_k > k or nums[i] > mid)
            return false;
        }

        return true;
    }



    int splitArray(vector<int>& nums, int k) {
        
        int start =0;
        int end = 0;

        if(k>nums.size())return -1;

        int n =nums.size();
        for(int i=0;i<n;i++)
        {
            end += nums[i];
        }

        int ans =-1;
        while( start <= end )
        {
            int mid = start + (end-start)/2;

            if(isValid(mid,nums,k))
            {
                ans = mid;
                end = mid -1;
            }
            else
            {
                start = mid+1;
            }
        }
        return ans;
    }
};
-------------------------------------------------------
class Solution {
public:


//[2,3,1,2,4,3] is the test case things get failed
// why ?
//  return subarrayCount==k; was there in my answer
// i thought i would get only answer when this condition satisfied
// which was actually true
// but by looking at this test case i reliased 
// return subarrayCount<=k; my condition were not getting satisfied 
// but i was able to minimise the answer
// hence all test case passed

// to solve a hard leetcode isnt that difficult when you are comfortable 
// with identiying the technique


    bool isValid(int mid,int n,vector<int> nums,int k)
    {
        int sum=0;
        int subarrayCount=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];

            if(nums[i]>mid)
            return false;

            if(sum>mid)
            {
                sum=nums[i];
                subarrayCount++;
            }
        }
        return subarrayCount==k;

    }
    int splitArray(vector<int>& nums, int k) {
        
        int start =0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        sum+=nums[i];
        int end =sum;
        int ans=0;

        while(start<=end)
        {
            int mid = start + (end-start)/2;

            if(isValid(mid,n,nums,k))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
};