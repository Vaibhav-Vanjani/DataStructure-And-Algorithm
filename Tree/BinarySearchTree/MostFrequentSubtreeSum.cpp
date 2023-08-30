/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int helper(TreeNode* root,unordered_map<int,int> &mp,int &cnt)
    {
        if(!root)return 0;
        
        int l = helper(root->left,mp,cnt);
        int r = helper(root->right,mp,cnt);

        int sum=root->val+l+r;
        mp[sum]++;
        cnt = max(cnt,mp[sum]);
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        int cnt=0;
        unordered_map<int,int> mp;
        int  x =  helper(root,mp,cnt);

        vector<int> ans;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==cnt)
            ans.push_back(it->first);
        }
        return ans;

        
    }
};