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
    vector<int> inorderTraversal(TreeNode* root) {
        
        TreeNode* curr = root;
        vector<int> ans;
    

        while(curr)
        {
            if(curr->left)
            {
                TreeNode* node = curr->left;
                TreeNode* nodeStar = curr->left; 
                while(node->right)node=node->right;
                node->right = curr;  
                curr->left = NULL;
                curr = nodeStar;
            }
            else 
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
           
        }
        return ans;
    }
};