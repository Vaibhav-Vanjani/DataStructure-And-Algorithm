// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
  public:
  
  int data;
  Node* prev;
  Node* next;
    
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};


Node* insertAtHead(Node* &head,int d)
{
    Node* temp = new Node(d);
 
    if(!head)
    return temp;
    
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

Node* insertAtTail(Node* &head,int d)
{
    Node* temp = new Node(d);
    if(!head)
    return temp;
    
    Node* traverseNode = head;
    
    while(traverseNode->next)
    traverseNode=traverseNode->next;
    
    traverseNode->next = temp;
    temp->prev = traverseNode;
    
    return head;
}

Node* insertAtNthPosition(Node* &head,int d,int pos)
{
    int count =1;
    Node* temp = head;
    Node* nthNode = new Node(d);
    
    if(pos==1)
    return insertAtHead(head,d);
    
    while(temp && count < pos-1)
    {
        temp=temp->next;
        count++;
    }
    
    if(count!=(pos-1))
    return insertAtTail(head,d);
    
    Node* tempNext = temp->next;
    nthNode->next = tempNext;
    temp->next = nthNode;
    nthNode->prev = temp;
    tempNext->prev = nthNode;
    return head;
}

Node* deleteHead(Node* &head)
{
    if(!head)
    {
        cout<<"there is no element in LL"<<endl;
        return NULL;
    }
    
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    
    return head;
}

Node* deleteTail(Node* &head)
{
    if(!head)
    {
        cout<<"there is no element in LL"<<endl;
        return NULL;
    }
    
    if(!head->next)
    return deleteHead(head);
    
    Node* temp = head;
    while(temp->next->next)
    {
        temp=temp->next;
    }
        
    temp->next = NULL;
    return head;
}

Node* deleteAtNthPos(Node* &head,int n)
{
    int count =1;
    if(n==1)
    return deleteHead(head);
    
    Node* temp = head;
    while(temp && (count < (n-1)))
    {
        temp = temp->next;
        count++;
    }
    
    if(count!=(n-1))
    return deleteTail(head);
    
    Node* tempNext = temp->next;
    temp->next = tempNext->next;
    tempNext->next->prev = temp;
    
    return head;
}


void printLL(Node* &head)
{
    Node* temp = head;
    
    while(temp)
    {
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}

int main()
{
    Node* head = new Node(1);
    printLL(head);
    
    cout<<"insertAtHead"<<endl;
    Node* newHead = insertAtHead(head,3);
    printLL(newHead);
      
    cout<<"insertAtTail"<<endl;
    Node* newHead1 = insertAtTail(newHead,2);
    printLL(newHead1);
    
    cout<<"insertAtNthPosition"<<endl;
    Node* newHead2 = insertAtNthPosition(newHead1,4,2);
    printLL(newHead2);
    
    // cout<<"deleteHead"<<endl;
    // Node* newHead3 = deleteHead(newHead2);
    // printLL(newHead3);
    
    // cout<<"deleteTail"<<endl;
    // Node* newHead4 = deleteTail(newHead3);
    // printLL(newHead4);
    
    cout<<"deleteAtNthPos"<<endl;
    Node* newHead3 = deleteAtNthPos(newHead2,3);
    printLL(newHead3);
    
    
    return 0;
}   