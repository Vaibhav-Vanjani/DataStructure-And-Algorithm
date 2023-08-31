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

    TreeNode* helper(int &indx,vector<int>& postorder, int is,int ie,vector<int>& inorder)
    {
        if(is>ie)return NULL;

        int ele = postorder[indx];
        int pos=-1;
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==ele)
            {
                pos = i;
                break;
            }
        }

        if(pos==-1)return NULL;
        indx--;

        TreeNode* root = new TreeNode(inorder[pos]);

        root->right = helper(indx,postorder,pos+1,ie,inorder);
        root->left = helper(indx,postorder,is,pos-1,inorder);
        return root;

    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int indx = postorder.size()-1;
        int n = inorder.size();
        TreeNode* ans = helper(indx,postorder,0,n-1,inorder);
        return ans;

    }
};