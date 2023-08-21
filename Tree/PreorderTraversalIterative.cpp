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
    vector<int> preorderTraversal(TreeNode* root) {
        
        TreeNode* curr = root;
        vector<int> ans;
        if(!curr)return ans;
        stack<TreeNode*> st;
        st.push(root);

        while(curr)
        {
            ans.push_back(curr->val);
            st.pop();

            if(curr->left)
            {
                if(curr->right)st.push(curr->right);
                curr=curr->left;
            }
            else if(curr->right)
            {
                curr=curr->right;
            }
            else
            {
                if(!st.empty())
               { 
                   curr=st.top();
                   st.pop();
               }
                else
                return ans;
            }

            st.push(curr);
        }
        return ans;
    }
};