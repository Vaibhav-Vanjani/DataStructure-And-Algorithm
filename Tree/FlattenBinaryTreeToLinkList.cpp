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

   TreeNode* preorder(TreeNode* &root)
    {
        // TreeNode* help = new TreeNode(root->val);

        if(!root)return NULL;

        TreeNode* l = preorder(root->left);
        TreeNode* r = preorder(root->right);
        root->left = NULL; 
        if(l)
        {
            root->right = l;
            while(l->right)
            {
                l=l->right;
            }
            l->right = r ;
       } 
       return root;

    }

    void flatten(TreeNode* root) {
        
        preorder(root);
        // return root;
    }
};