class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n =nums.size();
        if(n==1)return nums[0];
        
        int sum = 0,ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans = max(sum,ans);
            if(sum<0)sum=0;
        }
        return ans;
    }
};