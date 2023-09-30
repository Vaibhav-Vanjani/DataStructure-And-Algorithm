class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
       unordered_map<int,int> mp;
       int n = nums.size();
       int i=0;
        int j=0;
        int dups=0,cnt=0,ans=0;

        vector<int> v;
        set<vector<int>> st;
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            cnt=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]%p==0)cnt++;
                if(cnt>k)break;
                v.push_back(nums[j]);
                st.insert(v);
            }
            v.clear();
        }

        return st.size(); 
  }
};