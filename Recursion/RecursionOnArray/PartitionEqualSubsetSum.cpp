class Solution {
public:

    bool subset(int i,vector<int> &nums,int sum,int dp[201][20000])
    {
        if(sum == 0)return true;
        if(i==nums.size())return false;

        if(dp[i][sum] != -1)return dp[i][sum];

        if(sum<nums[i])
        {
            return dp[i][sum] = subset(i+1,nums,sum,dp);
        }
        else
        {
            bool l = subset(i+1,nums,sum,dp);
            bool r = subset(i+1,nums,sum-nums[i],dp);
            if(r or l)return dp[i][sum] = true;
            else return dp[i][sum] = false;
        }

    }


    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        int dp[201][20000];
        memset(dp,-1,sizeof(dp));
        sum=sum/2;
        return subset(0,nums,sum,dp);
    }
};