class Solution {
public:

    int numFactoredBinaryTrees(vector<int>& nums) {
    
   unordered_map<int,long long> freq,cnt;
   sort(nums.begin(),nums.end());
   int n = nums.size();
   for(int i=0;i<n;i++)
   {
       freq[nums[i]]++;
       cnt[nums[i]]++;
    }
   int ans=0;
   long long prod,count,ele,num;
   int mod = 1e9+7;

   for(int i=1;i<n;i++)
    {     
        ele = nums[i];
            for(int j=0;j<i;j++)
            {
                num = nums[j];
                if(ele%num==0)
                {
                    int k = nums[i]/nums[j];
                    if(freq.count(k))
                    cnt[nums[i]]=(cnt[nums[i]]+1LL*cnt[k]*cnt[nums[j]])%mod;
                }
            }
     }
     
   
    for(int i=0;i<n;i++)
    {
        ans=(ans%mod+cnt[nums[i]])%mod;
    }
    return ans;
 }
};