

    ListNode* recursiveLL(ListNode* &head)
    {
        if(!head or !head->next)return head;

        ListNode* x= recursiveLL(head->next);

        head->next->next = head;
        head->next = NULL;

        return x;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head or !head->next)return head;

        int dummyK1=k;
        ListNode* dummyhead1=head;
        while(dummyhead1 && dummyK1){
            dummyhead1=dummyhead1->next;
            dummyK1-=1;
        }

        if(dummyK1)return head;

         ListNode* x = reverseKGroup(dummyhead1,k);

        int dummyK2=k-1;
        ListNode* dummyhead2=head;
        while(dummyhead2->next and dummyK2){
            dummyhead2=dummyhead2->next;
            dummyK2-=1;
        }
        dummyhead2->next=NULL;

        ListNode* y = recursiveLL(head);

       
        ListNode* dummyhead3=y;
        while(dummyhead3->next){
            dummyhead3=dummyhead3->next;
        }
        dummyhead3->next=x;

        return y;
    }
