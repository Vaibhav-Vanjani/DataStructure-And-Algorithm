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
        int cnt=0;

        while(head)
        {
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    
    void helper(ListNode* head,int k,vector<ListNode*> &ans,int length)
    {
         if(length<=k)
         {
             ListNode* abc;
             while(head)
             {
                 k--;
                //  ans.push_back(head->data);
                abc = head->next;
                head->next=NULL;
                ans.push_back(head);
                 head=abc;
             }

           
             while(k)
             {
                 ans.push_back(NULL);
                 k--;
             }
         }
         else
         {
             if(length%k == 0)
             {
                 ListNode* start=head;
                 ListNode* prev = head;
                 int temp = length/k;
                 int temptemp = temp;

                 for(int i=0;i<k;i++)
                 {
                    start=head;
                     while(temp)
                     {
                           temp--;
                           prev=head;
                           if(!prev)return;
                           head=head->next;
                     }
                         prev->next=NULL;
                        ans.push_back(start);
                        start=head;
                     temp = temptemp;
                 }

             }
             else
             {
                 ListNode* start = head;
                 ListNode* prev = head;
                int temp = length/k;
                 int temptemp = temp;
                 temp = temp+1;

                    start=head;
                     while(temp)
                     {
                           temp--;
                           prev = head;
                           head=head->next;
                     }
                     prev->next = NULL;
                     ans.push_back(start);

                helper(head,k-1,ans,length-temptemp-1);

             }
         }
    }


    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int length = getLength(head);
        vector<ListNode*> ans;
        helper(head,k,ans,length);
         return ans;

    }
};