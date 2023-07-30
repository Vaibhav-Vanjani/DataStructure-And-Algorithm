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
    Node* newHead2 = insertAtNthPosition(newHead1,3,2);
    printLL(newHead2);
    
    return 0;
}
