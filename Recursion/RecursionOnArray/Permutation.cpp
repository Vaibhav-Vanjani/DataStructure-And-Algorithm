class Solution {
public:

    void getPermutation(vector<int>& nums,int n,vector<vector<int>> &ans,unordered_map<int,int> mp,vector<int> v)
    {
        if(v.size() == n)
        {
            ans.push_back(v);
            return ;
        }


        for(int i=0;i<n;i++)
        {
                 if(!mp[nums[i]])
                {
                    mp[nums[i]]=1;
                    v.push_back(nums[i]);
                    getPermutation(nums,n,ans,mp,v);
                    v.pop_back();
                    mp[nums[i]]=0;
                }
        }
    }



    vector<vector<int>> permute(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=0;
        }

        vector<int> v;
        vector<vector<int>> ans;
        getPermutation(nums,n,ans,mp,v);
        return ans;
    }
};