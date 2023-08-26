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

    // void helper(TreeNode* root,int val,TreeNode* &head)
    // {

    //     if(!root)return ;
    //     if(root->val == val)
    //     {
    //         head = root;
    //         return ;
    //     }
    //     else if(root->val>val)
    //     helper(root->left,val,head);
    //     else if(root->val<val)
    //     helper(root->right,val,head);
    // }


    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode* head=NULL;
        // helper(root,val,head);
        // return head;

        while(root)
        {
            if(root->val == val)
            return root;
            else if(root->val > val)
            {
                root=root->left;
            }
            else
            {
                root=root->right;
            }
        }
        return root;
    }
};