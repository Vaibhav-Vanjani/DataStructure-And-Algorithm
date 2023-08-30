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

    void pathToLeaf(TreeNode* root,unordered_map<long long,long long> &mp,long long &cnt,long long sum,int k)
    {
        if(!root)return ;
        sum+=root->val;
        
        if(sum==k)
        cnt++;

        if(mp.find(sum-k)!=mp.end())
        cnt+=mp[sum-k];

        mp[sum]++;

        pathToLeaf(root->left,mp,cnt,sum,k);
        pathToLeaf(root->right,mp,cnt,sum,k);
    
       mp[sum]--;
       sum-=root->val;
    }


    int pathSum(TreeNode* root, int targetSum) {
        
       long long cnt=0;
        unordered_map<long long,long long> mp;
        pathToLeaf(root,mp,cnt,0,targetSum);
        return cnt;
    }
    
};