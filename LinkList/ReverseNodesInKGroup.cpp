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

    int getLength(ListNode* head)
    {
        ListNode* temp = head;
        int count =0;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }

    ListNode* helper(ListNode* &head,int l,int k)
    {
        if(!head or !head->next)return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* headStart=curr;
        ListNode* nNext = NULL;
            
            if(l>=k)
            {
            int temp =0;
            while(curr && temp<k)
            {
                nNext = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nNext ;
                temp++;
            }

             if(curr)
             {
                 ListNode* x = helper(curr,l-k,k);
                 headStart->next = x;
            }
            return prev;

           }
           else 
           return curr; 

            
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int l = getLength(head);
        return helper(head,l,k);
    }
};