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
class Solution {
public:

    ListNode* reverseLL(ListNode* &head)
    {
        if(!head or !head->next)return head;
        
        ListNode* headNode = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;

        return headNode;
    }


    bool isPalindrome(ListNode* head) {

        if(!head or !head->next)return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* middle = head;

        while(fast and fast->next)
        {
            middle = slow;
            slow=slow->next;
            fast=fast->next->next;
        }
          
        ListNode* middleNode = reverseLL(slow);
        
        ListNode* oddNode = middleNode;
        middle->next=middleNode;
        slow = head;
        // if(slow->val == 1)return true;
     
        while(middleNode && slow!=oddNode)
        {
            if(slow->val != middleNode->val)
            return false;

            slow = slow->next;
            middleNode = middleNode->next;
        }
        
        return true;
    }
};