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

   void helper(TreeNode *root,long long &sum)
    {
        if(!root)return ;
        if(!root->left && !root->right)return ;

        if(!((root->val)%2))
       {    if(root->left)
            {
                TreeNode* x = root->left;
                if(root->left->left)
                {
                    sum+=(long long)x->left->val;
                }
                 if(root->left->right)
                {
                    sum+=(long long)x->right->val;
                }
            }

            if(root->right)
            {
                 if(root->right->left)
                {
                    sum+=(long long)root->right->left->val;
                }
                 if(root->right->right)
                {
                    sum+=(long long)root->right->right->val;
                }
            }
        }

        helper(root->left,sum);
        helper(root->right,sum);
    }


    int sumEvenGrandparent(TreeNode* root) {
        
        long long sum = 0;
        helper(root,sum);
        return sum;
    }
};