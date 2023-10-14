class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int take = -1;
        int n = nums.size();
        for(int j=n-1;j>0;j--)
        {
            if(nums[j]>nums[j-1])
            {
                take=j;
                break;
            }
        }

        if(take==-1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }

        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[take-1])
            {
                swap(nums[i],nums[take-1]);break;
            }
        }
       
        sort(nums.begin()+take,nums.end());
        return ;
    }
};