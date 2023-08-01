/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

    // edge case
    // 1. if a single node is there
    // 2. no cylce with fast at last node
         
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            break;
        }

         if(!fast or !fast->next)return NULL;

        slow = head;

        while(fast != slow)
        {
            slow = slow->next ;
            fast = fast->next ;
        }
        return slow;

    }
};