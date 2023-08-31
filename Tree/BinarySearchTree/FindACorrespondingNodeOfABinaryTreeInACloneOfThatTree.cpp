/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    void helper(TreeNode* &root,TreeNode* &cloned,TreeNode* &target,TreeNode* &ans)
    {
        if(!root)return;

        if(root == target)
        ans=cloned;

        helper(root->left,cloned->left,target,ans);
        helper(root->right,cloned->right,target,ans);
    }


    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        

     TreeNode* ans = NULL;
    helper(original,cloned,target,ans);
    return ans;
    }
};