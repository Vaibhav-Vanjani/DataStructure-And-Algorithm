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
    vector<int> largestValues(TreeNode* root) {
        
        queue<TreeNode*> q;
        if(root)q.push(root);
        vector<int> ans;

        while(!q.empty())
        {
            int size = q.size();
            int maxi = INT_MIN;
            for(int i=0;i<size;i++)
            {
                  TreeNode* fr  = q.front();
                  q.pop();
                  
                  maxi = max(maxi,fr->val);
                  if(fr->left)q.push(fr->left);
                  if(fr->right)q.push(fr->right);
            }
            ans.push_back(maxi);
        }
        return ans;
        
    }
};