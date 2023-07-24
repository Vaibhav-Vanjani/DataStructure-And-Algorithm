class Solution {
public:

    int ceil(int a ,int b)
    {
        if(a<=b)
        return 1;
        
        if(a%b==0)
        return a/b;
        else
        return a/b+1;
    }


    bool isValid(int mid ,vector<int> nums,int threshold)
    {
        int ans =0;
        int n = nums.size();
       for(int i=0;i<n;i++)
       {
           ans+=ceil(nums[i],mid);
       }
       return ans<=threshold;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int start = 1;
        int end = 0;

        for(int i=0;i<nums.size();i++)
        {
            end = max(nums[i],end);
        }

        int ans = -1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;

            if(isValid(mid,nums,threshold))
            {
                ans = mid;
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