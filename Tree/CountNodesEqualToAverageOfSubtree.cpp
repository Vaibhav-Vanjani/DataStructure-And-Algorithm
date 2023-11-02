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

    pair<int,int> helper(TreeNode* root,int &ans)
    {
        if(!root)
        {
            return {0,0};
        }

        pair<int,int> l = helper(root->left,ans);
        pair<int,int> r = helper(root->right,ans);

        int lCnt = l.first;
        int rCnt = r.first;
        int lSum = l.second;
        int rSum = r.second;
        int value = root->val;

        int rt = (l.second + r.second + value)/(l.first+r.first+1);

        ans+=(value)==(rt);
        return {(l.first+r.first+1),(l.second + r.second + value)};
    }


    int averageOfSubtree(TreeNode* root) {
            int ans = 0;
           pair<int,int> o =  helper(root,ans);
           return ans;
    }
};