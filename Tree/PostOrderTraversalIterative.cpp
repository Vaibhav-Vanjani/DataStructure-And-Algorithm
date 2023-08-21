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
    vector<int> postorderTraversal(TreeNode* root) {
        
        TreeNode* curr = root;
        vector<int> ans;
        if(!curr)return ans;
        stack<TreeNode*> st;
        st.push(root);

        while(curr)
        {
            if(curr->left)
            {
                 TreeNode* lft = curr;
                if(curr->right){
                    st.push(curr->right);
                    lft->right=NULL;
                }
                curr=curr->left;
                lft->left=NULL;
                 st.push(curr);
            }
            else if(curr->right)
           { 
               TreeNode* rt = curr;
               curr=curr->right;
               rt->right=NULL;
                st.push(curr);
           }
            else 
            {
                if(!st.empty())
                {
                    
                    ans.push_back(st.top()->val);
                    st.pop();
                    
                    if(st.empty())return ans;
                    else curr=st.top();
                }
                else 
                return ans;
            }
        }
        return ans;
    }
};