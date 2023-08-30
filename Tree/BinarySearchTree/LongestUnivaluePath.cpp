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

    pair<int,int> helper(TreeNode* root,int &ans)
    {
        if(!root)return {INT_MIN,0};
        if(!root->left && !root->right)
        {
            return {root->val,1};
        }

        pair<int,int> l = helper(root->left,ans);
        pair<int,int> r = helper(root->right,ans);

       
            if((root->val == l.first) && (root->val == r.first))
            {
                ans = max(l.second + r.second + 1,ans);
                return {root->val,max(l.second,r.second) + 1};
            }
            else if((root->val == l.first) && (root->val != r.first))
            {
                 ans = max(l.second + 1,ans);
                return {root->val,l.second + 1};
            }
            else if(root->val != l.first && root->val == r.first)
            {
                 ans = max(r.second + 1,ans);
                return {root->val,r.second + 1};
            }
            else
            {
                return {root->val,1};
            }
    }


    int longestUnivaluePath(TreeNode* root) {
    
        if(!root)return 0;

        int ans = 1;
        pair<int,int> a = helper(root,ans);
        return max(ans-1,0);
    }
};