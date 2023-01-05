class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n=nums.size();
        if(n==1)
        return 0;

        if(nums[0]>nums[1])
        return 0;

        if(n>1)
        {
            if(nums[n-1]>nums[n-2])
            return (n-1);
        }

        int start=0;
        int end=n-1;

        while(start<=end)
        {
            int mid =start + (end-start)/2;
            if((mid-1)==-1)
            {
                if(nums[mid]>nums[mid+1])
                return mid;
                else
                start=mid+1;
            }
           else if((mid+1)==n)
            {
                if(nums[mid]>nums[mid-1])
                return mid;
                else
                end=mid-1;
            }
            else{
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            return mid;
            else if(nums[mid]<nums[mid-1])
            end=mid-1;
            else
            start=mid+1;
            }
        }

        return -1;

       
    }
};