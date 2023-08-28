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

    void helper(TreeNode* root,TreeNode* &head)
    {
        if(!root)return ;

        helper(root->left,head);
        head->right = new TreeNode(root->val);
        head=head->right;
        helper(root->right,head);       
    }

    TreeNode* balancef(TreeNode* start)
    {
        
         if(!start)return NULL;
         if(!start->left && !start->right)
         {
             TreeNode* ans = new TreeNode(start->val);
             return ans;
         }

         TreeNode* s = start;
         TreeNode* p = start;
         TreeNode* f = start;

         while(f && f->right)
         {
             p = s;
             s=s->right;
             f=f->right->right;
         }

         p->right=NULL;
         TreeNode* ans = new TreeNode(s->val);
         s=s->right;
        //  cout<<

         ans->left = balancef(start);
         ans->right = balancef(s);
         return ans;
    }



    TreeNode* balanceBST(TreeNode* root) {
        
        TreeNode* head = new TreeNode(1);
        TreeNode* start = head;
        helper(root,head);
      
        start = start->right;
        // return start;

        // TreeNode* ans=NULL;
        TreeNode* x =  balancef(start);
        return x;

    }
};