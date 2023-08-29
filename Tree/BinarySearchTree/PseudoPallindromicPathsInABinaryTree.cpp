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

    // bool isPallindrome(vector<int> ans)
    // {
    //     unordered_map<int,int> mp;
    //     int n = ans.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         mp[ans[i]]++;
    //     }
    //     int cnt=0;
    //     for(auto it=mp.begin();it!=mp.end();it++)
    //     {
    //         if((it->second % 2) != 0)cnt++;
    //         if(cnt>1)return false;
    //     }
    //     return true;
    // }

    void helper(TreeNode* root,int &cnt,unordered_map<int,int> &mp)
    {
        if(!root)return ;

        // ans.push_back(root->val);
        mp[root->val]++;
        if(!root->left && !root->right)
        {
            int ans=0;
             for(auto it=mp.begin();it!=mp.end();it++)
                {
                    if((it->second % 2) != 0)ans++;
                    if(ans>1)break;
                }

             if(ans<=1)cnt++;
            // return ;
        }

        helper(root->left,cnt,mp);
        helper(root->right,cnt,mp);
        mp[root->val]--;
    }


    int pseudoPalindromicPaths (TreeNode* root) {
        
        int cnt=0;
        unordered_map<int,int> mp;
        helper(root,cnt,mp);
        return cnt;
    }
};