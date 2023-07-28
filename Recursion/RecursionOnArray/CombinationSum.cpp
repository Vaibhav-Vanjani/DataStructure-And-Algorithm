class Solution {
public:

    void helper(int i,int sum,vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> temp)
    {
        if(sum>target or i==candidates.size())
        return;

        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }

        helper(i+1,sum,candidates,target,ans,temp);
        temp.push_back(candidates[i]);
        helper(i,sum+candidates[i],candidates,target,ans,temp);
        temp.pop_back();
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> temp;
        vector<vector<int>> ans;
        int sum=0;
        helper(0,sum,candidates,target,ans,temp);
        return ans;
    }
};