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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(!root)return NULL;
        
        if(root->val == key)
        {
            if(!root->left && !root->right)
            {
                return NULL;
            }
            else if(root->left && !root->right)
            {
                return root->left;
            }
            else if(!root->left && root->right)
            {
                return root->right;
            }
            else
            {
                TreeNode* x = root->left;
                while(x->right)x=x->right;
                root->val = x->val;
               root->left = deleteNode(root->left,x->val);
            }
        }

       root->left =  deleteNode(root->left,key);
       root->right = deleteNode(root->right,key);
       return root;
        
    }
};