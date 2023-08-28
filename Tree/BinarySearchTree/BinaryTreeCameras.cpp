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

    int helper(TreeNode* root,int &ans)
    {
        if(!root)return 2;

        int l = helper(root->left,ans);
        int r = helper(root->right,ans);

        if(!l or !r)
        {
            ans++;
            return 1;
        }
        else if(l==1 or r==1)
        {
            return 2;
        }
        else
        {
            return 0;
        }
        
    }

    int minCameraCover(TreeNode* root) {
        int ans = 0;

        if(!root->left && !root->right)return 1;

       int abc =  helper(root,ans);
       if(!abc)ans++;
       return ans;
    }
};