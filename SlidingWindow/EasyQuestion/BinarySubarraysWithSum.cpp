class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        //same as subarray sum with sum k

        unordered_map<int,int> mp;
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];

            if(sum==goal)count++;

            if(mp.find(sum-goal)!=mp.end())count+=mp[sum-goal];

            mp[sum]++;
        }
        return count;
    }
};