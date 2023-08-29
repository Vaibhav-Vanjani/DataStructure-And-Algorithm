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
    bool isCompleteTree(TreeNode* root) {
        
        bool flag = false;
          if(!root)
            return true;
        
        queue<TreeNode*> q ; 
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            // vector<int> v;
            for(int i =0;i<size;i++)
            {
            
            TreeNode* x = q.front();
            q.pop();
            
            if(!x->left && x->right)return false;
            if(x->left)
            {
                if(flag)return false;

                q.push(x->left);
            }
            
            if(x->right)
            {
                if(flag)return false;

                q.push(x->right);
            }
            if(!x->left or !x->right)flag = true; 
                // v.push_back(x->val);
            } 
        }
        return true;
    }
};