class Solution {
public:

    int atmost(vector<int>& nums, int k)
    {
        unordered_map<int,int> mp;
        int i=0,j=0;
        int n = nums.size();
        int mpCount=0,ans=0;
        while(j<n)
        {
            mp[nums[j]]++;
            if(mp[nums[j]]==1)mpCount++;
            while(mpCount>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mpCount--;
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
       
      return ( atmost(nums,k) - atmost(nums,k-1));
    }
};