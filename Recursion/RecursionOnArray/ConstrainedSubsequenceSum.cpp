class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = nums[0];
        int dp[n];
        
        for(int i=0;i<n;i++)
        dp[i]=nums[i];

        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        
        for(int i=1;i<n;i++)
        {
            while(!pq.empty() && ((i-pq.top().second) > k))
            pq.pop();

            if(!pq.empty() && ((nums[i]+pq.top().first)>=dp[i]))
                dp[i]=nums[i]+pq.top().first;
            else
                dp[i]=nums[i];

            pq.push({dp[i],i});
            res = max(res,dp[i]);
        }
        return res;

    }
};