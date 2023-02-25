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

    int maxHeight(TreeNode* root,int &d)
    {
        if(!root)return 0;
        if(root and !root->left and !root->right)return 1;
        
        int ld = maxHeight(root->left,d);
        int rd = maxHeight(root->right,d);
        
        d=max(d,ld+rd);
        return 1 +max(ld,rd);
       
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root or (root and !root->left and !root->right))return 0;

        int d=0;
        int height = maxHeight(root,d);
        return d;
    }
};