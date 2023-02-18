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


        void helper(TreeNode* root)
        {
             
             if(!root or (!root->left and !root->right))return ;
            
            TreeNode* x = root->left;
            root->left=root->right;
            root->right = x;

            helper(root->left);
            helper(root->right);
        }


    TreeNode* invertTree(TreeNode* root) {
        
        if(!root or (!root->left and !root->right))return root;

        helper(root);
        return root;
    }
};