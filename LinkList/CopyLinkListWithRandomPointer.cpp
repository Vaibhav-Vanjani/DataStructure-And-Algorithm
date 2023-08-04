/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)return head;


        Node* temp = new Node(0);
        Node* tempCopy = temp;
        Node* copyHead = head;
        Node* copyHead1 = head;

        // creating a copy of list with only next pointer
        // and mapping new nodes with old nodes
        unordered_map<Node*,Node*> mp;
        while(copyHead)
        {
            Node* curr = new Node(copyHead->val);
            mp[copyHead] = curr;
            temp->next = curr;
            temp = curr;

            copyHead = copyHead->next;
        }
        //copyHead == NULL
        Node* newList = tempCopy->next;
        Node* answer = newList;

        while(copyHead1)
        {
            newList->random = mp[copyHead1->random];
            copyHead1=copyHead1->next;
            newList=newList->next;
        }
        return answer;
    }
};