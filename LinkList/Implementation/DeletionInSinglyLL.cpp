// Online C++ compiler to run C++ program online
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
  public:
  int data ;
  Node* next ;
  
  Node(int data)
  {
      this->data = data;
      this->next = NULL;
  }
};

void insertAtHead(Node* &head,int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtMiddle(Node* &head,int d)
{
    Node* middle = new Node(d);
    
    Node* fast = head ;
    Node* slow = head ;
    
    if(!fast or !fast->next)
    {
        insertAtHead(head,d);
    }

    while(fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    Node* slowNextNode = slow->next;
    slow->next = middle;
    middle->next = slowNextNode;
}

void insertAtTail(Node *&head,int d)
{
    Node* tail = new Node(d);
    Node* temp = head;
    
    if(!temp)
    {
        head = tail;
        return ;
    }
    
    while(temp->next)
    {
      temp=temp->next;    
    }
    temp->next = tail;
    return;
}

void insertAtNthPosition(Node* &head,int n,int d)
{
    int count = 1;
    Node *temp = head;
    Node* nthNode = new Node(d);
    while(temp && count<(n-1))
    {
        temp = temp -> next;
        count++;
    }
    
    if(count != (n-1))
     insertAtTail(head,d);
 
    Node *tempNext = temp->next;
    temp->next = nthNode;
    nthNode->next = tempNext;
    return ;
}

Node* deleteFromHead(Node* &head)
{
    if(!head)
    {
        cout<<"there is no head";
       return NULL;
    }
    
    if(!head->next)
    {
        cout<<"head has been deleted";
        return NULL;
    }
    
    head=head->next;
    return head;
}

Node* deleteFromTail(Node* &head)
{
    Node* temp = head;
    
    if(!temp)
    {
        cout<<"there is no node in LL";
        return NULL;
    }
    
    if(!temp->next)
    {
        cout<<"last element is now deleted";
        return NULL;
    }
    
    while(temp->next->next)
    {
        temp=temp->next;
    }
    
    temp->next=NULL;
    return head;
}

Node* deleteFromNthPosition(Node* &head,int n)
{
    int count = 1;
    Node* temp = head;
    
    if(count == n)
    return deleteFromHead(head);
    
    while(temp && (count < (n-1)))
    {
        temp=temp->next;
    }
    
    if(count != (n-1))
    return deleteFromTail(head);
    
    temp->next = temp->next->next;
    return head;
}

void printLL(Node* &head)
{
    Node *temp = head;    
    while(temp)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}


int main() {
    // Write C++ code here
   
   Node * start = new Node(1);
   insertAtHead(start,2);
//   printLL(start);
   
//   cout<<"insertAtHead"<<endl;
   insertAtHead(start,35);
//   printLL(start);
   
//   cout<<"insertAtTail"<<endl;
   insertAtTail(start,40);
//   printLL(start);
   
//   cout<<"insertAtMiddle"<<endl;
   insertAtMiddle(start,29);
//   printLL(start);
   
//   cout<<"insertAtNthPosition"<<endl;
   insertAtNthPosition(start,4,11);
   printLL(start);
   
   cout<<"deleteFromHead"<<endl;
   Node* newHead = deleteFromHead(start);
   printLL(newHead);
   
   cout<<"deleteFromTail"<<endl;
   Node* newhead1 = deleteFromTail(newHead);
   printLL(newhead1);
   
   cout<<"deleteFromNthPosition"<<endl;
   Node* newHead2 = deleteFromNthPosition(newhead1,2);
   printLL(newHead2);
   
   
   
    return 0;
}