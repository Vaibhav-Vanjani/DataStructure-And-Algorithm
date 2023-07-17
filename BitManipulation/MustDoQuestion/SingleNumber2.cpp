class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        vector<int> cnt(32,0);

        for(int i=31;i>=0;i--)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]&(1<<i))
                cnt[i]++;
            }
        }

        long int ans=0;
        for(int i=31;i>=0;i--)
        {
            if(cnt[i]%3)
            ans+=1<<i;
        }

        return ans;



    }
};