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
        if(!curr)return ans;
        stack<TreeNode*> st;
        st.push(curr);

        while(curr)
        {
            if(!curr->left)
            {
                ans.push_back(curr->val);
                st.pop();


                if(curr->right)
                {
                    TreeNode* x = curr;
                    curr=curr->right;
                    st.push(curr);
                    x->right = NULL;
                }
                else
                {
                    if(!st.empty())
                    curr=st.top();
                    else
                    return ans;
                }
            }
            else
            {
                TreeNode* x = curr;
                curr=curr->left;
                 st.push(curr);
                 x->left=NULL;

            }
        }
        return ans;
    }
};