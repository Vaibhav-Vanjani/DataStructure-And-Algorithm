class Solution {
public:

    void helper(vector<int> nums,int i,vector<int> temp,vector<vector<int>> &ans,int n)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }

        helper(nums,i+1,temp,ans,n);
        temp.push_back(nums[i]);
        helper(nums,i+1,temp,ans,n);

        // why temp.pop_back() is not necessary ? 
        // temp.pop_back();
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> temp;
        vector<vector<int>> ans;
        
        helper(nums,0,temp,ans,nums.size());
        return ans;
    }
};