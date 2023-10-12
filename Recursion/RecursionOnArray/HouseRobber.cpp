class Solution {

    int helper(int indx,int n,int sum,int &maxi,vectorint& nums,vectorvectorint &dp)
    {
        if(indx=n)
        {
            maxi = max(sum,maxi);
            return maxi;
        }

        if(dp[indx][sum] != -1)return dp[indx][sum];

        int l = helper(indx+1,n,sum,maxi,nums,dp);
        for(int i=indx;in;i++)
        {
            int r = max(l,helper(i+2,n,sum+nums[i],maxi,nums,dp));  
            maxi = max(maxi,r);
        }
        return dp[indx][sum] = maxi;
    }
public
    int rob(vectorint& nums) {
        
        int maxi=-1;
        int sum=0;
        int n = nums.size();
        vectorvectorint dp(101,vectorint (40000,-1));

        return helper(0,n,sum,maxi,nums,dp);
    }
};