/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

   

    TreeNode* sortedListToBST(ListNode* head) {
     
     if(!head)return NULL;
     if(!head->next)
     {
         TreeNode* root = new TreeNode(head->val);
         return root;
     }

     ListNode* f = head;
     ListNode* s = head;
     ListNode* prev = head;

     while(f and f->next)
     {  
        prev = s;
         s=s->next;
         f=f->next->next;
     }
    
     prev->next = NULL;
     ListNode* mid = s;
     ListNode* start = head;

     TreeNode* root = new TreeNode(mid->val);
     mid=mid->next;

    root->left = sortedListToBST(start);
    root->right = sortedListToBST(mid);

     return root;


     

    }
};