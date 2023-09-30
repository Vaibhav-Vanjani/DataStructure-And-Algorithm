class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
       
        // (i+1)*(n-i)
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int count = mp.size();
        int ans = 0;

        int i=0;
        int j=0;
        int mapSize=0;
        mp.clear();

        while(j<n)
        {
            mp[nums[j]]++;
            if(mp[nums[j]]==1)mapSize++;

            while(mapSize==count)
            {
                ans+=(n-j); //gets right count
                mp[nums[i]]--;

                if(mp[nums[i]]==0)--mapSize;
                i++;// now ith index is of no use 
            }
          j++;
        }

        return ans;

        1 3 1 2 2
    
    }
};