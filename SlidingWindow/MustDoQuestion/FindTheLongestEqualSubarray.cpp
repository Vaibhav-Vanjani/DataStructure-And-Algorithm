class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>> maxheap;
        int i=0;
        int j=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        int ans=0;
        
        while(j<n)
        {
            mp[nums[j]]++;
            maxheap.push({mp[nums[j]],nums[j]});
            
            int ele = maxheap.top().second;
            int cnt = maxheap.top().first;
            int len = j-i+1;
            
            while((len - cnt)>k)
            {
                mp[nums[i]]--;
                
                if(nums[i]==ele)
                maxheap.pop();
                
                maxheap.push({mp[nums[i]],nums[i]}); 
                i++;
                
                
                len = j-i+1;
                cnt = maxheap.top().first;
                ele = maxheap.top().second;
            }
            
            ans = max(ans,cnt);
            j++;
        }
        return ans;
        
    }
};