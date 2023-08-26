    
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


class Node{
  
  public:
  int data;
  Node* left;
  Node* right;

    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void buildTree(int arr[],int i,Node* root,int n,Node* &head)
{
    if(i>=n)return ;
    
    if(i==0)
    {
      root = new Node(arr[i]);
      head=root;
      buildTree(arr,i+1,head,n,head);
    }
   
    if(root && arr[i]<root->data)
    {
        if(!(root->left))
        root->left=new Node(arr[i]);
        else
        buildTree(arr,i,root->left,n,head);
        
        buildTree(arr,i+1,head,n,head);
    }
    else if(root && arr[i]>root->data)
    {
        if(!(root->right))
        root->right=new Node(arr[i]);
        else
        buildTree(arr,i,root->right,n,head);
        
        buildTree(arr,i+1,head,n,head);
    }
}

void preorder(Node* root)
{
    if(!root)return ;
    
    cout<<root->data<<"->";
    
    preorder(root->left);
    preorder(root->right);
}

int main() {
   
   Node* root=NULL;
  Node* head = NULL;
  int arr[]={10 , 8 , 21, 7 , 27 , 5, 4 ,3 };
  buildTree(arr,0,root,8,head);
  
  preorder(head);
   
    return 0;
}
    
};