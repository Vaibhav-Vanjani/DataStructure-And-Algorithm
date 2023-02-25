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

    bool helper(TreeNode* myLeft,TreeNode* myRight)
    {
        if(!myLeft and !myRight)
        return true;


        if(myLeft and myRight) 
        {
            return (myLeft->val == myRight->val) && helper(myLeft->left,myRight->right) 
            && helper(myLeft->right,myRight->left); 
        }
        else if((myLeft and !myRight) or (!myLeft and myRight))
        {
            return false;
        }

        return true;
    }


    bool isSymmetric(TreeNode* root) {
           return helper(root->left,root->right);
    }
};