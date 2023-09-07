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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head or left==right)return head;

        ListNode* ans = head;
        ListNode* previous = head;
        int lft = left;
        while(left>1)
        {
            previous = head;
            head=head->next;
            --left;
        }


        ListNode* str = head;
        
        ListNode* prev=NULL;
        ListNode* curr = head;
        ListNode* nxt;
        right = right-lft+1;

        while(right && curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            right--;
        }
        
        if(lft>1)
        previous->next=prev;

        str->next = curr;

        if(lft==1)
        {
            return prev;
        }
        else if(lft>1)return ans;

        return NULL;


        

    }
};