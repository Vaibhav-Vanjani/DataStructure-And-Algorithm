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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
         ListNode *dummy = new ListNode(-1);
    ListNode *prevNode = dummy;
    int sum = 0, carry = 0;
    while (head1 != NULL || head2 != NULL || carry)
    {
        int digit1 = 0, digit2 = 0;
        if (head1 != NULL)
        {
            digit1 = head1->val;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            digit2 = head2->val;
            head2 = head2->next;
        }
        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        prevNode->next = new ListNode();
        prevNode = prevNode->next;
        prevNode->val=sum % 10;
    }
    if (carry != 0)
       { prevNode->next = new ListNode();
        prevNode=prevNode->next;
        prevNode->val=sum % 10;
}
    ListNode *res = dummy->next;
    delete dummy;
    return res;}
};