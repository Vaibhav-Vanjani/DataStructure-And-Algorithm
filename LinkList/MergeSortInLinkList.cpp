//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node* merge(Node* &headStart,Node* &tailStart)
    {
    
        Node* dummyNode = new Node(0);
        Node* ansNode = dummyNode;
        
        while(headStart && tailStart)
        {
            if(headStart->data <= tailStart->data)
            {
                dummyNode->next = headStart;
                headStart =headStart->next;
                dummyNode = dummyNode->next; 
            }
            else
            {
                dummyNode->next = tailStart;
                tailStart = tailStart->next;
                dummyNode = dummyNode->next; 
            }
        }
        
        while(headStart)
        {
                dummyNode->next = headStart;
                headStart =headStart->next;
                dummyNode = dummyNode->next;        
        }
        
        while(tailStart)
        {
                dummyNode->next = tailStart;
                tailStart = tailStart->next;
                dummyNode = dummyNode->next; 
        
        }
        return ansNode->next;
        
    }
    
    Node* middleLL(Node* head)
    {
         if(!head or !head->next)return head;
        
        Node* slow = head;
        Node* fast = head;

        if(fast && fast->next && !fast->next->next)
        return fast;
        
        
        while(fast && fast->next)
        {    // mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    
    Node* mergeSort(Node* head) {
        // your code here
        if(!head or !head->next)return head;
        
        Node* mid = middleLL(head);
        Node* midNext = mid->next;
        mid->next=NULL;
        
        Node* start = mergeSort(head);
        Node* end = mergeSort(midNext);
        
        Node* ans = merge(start,end);
        return ans;
    }
};



//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends