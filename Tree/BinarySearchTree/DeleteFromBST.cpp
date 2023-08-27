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
      this->data = d;
      this->left=NULL;
      this->right=NULL;
  }
};


void buildTree(int arr[],int i,Node* root,Node* &head,int n)
{
    if(i>=n)return;
    else if(i==0)
    {
       head = new Node(arr[i]);
       root = head;
       buildTree(arr,i+1,head,head,n);
    }
    else if(root->data > arr[i])
    {
        if(!root->left)
        {
            Node* temp = new Node(arr[i]);
            root->left = temp;
            buildTree(arr,i+1,head,head,n);
        }
        else
        {
             buildTree(arr,i,root->left,head,n);
        }
    }
    else
    {
          if(!root->right)
        {
            Node* temp = new Node(arr[i]);
            root->right = temp;
            buildTree(arr,i+1,head,head,n);
        }
        else
        {
             buildTree(arr,i,root->right,head,n);
        }
         
    }
}

void preorder(Node* root)
{
    if(!root)return ;
    
    preorder(root->left);
    cout<<root->data<<"->";
    preorder(root->right);
}


Node* deleteFromBst(Node* &root,int val)
{
    if(!root)return NULL;
    
    if(root->data == val)
    {
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        else  if(root->left && !root->right)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left && root->right)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->left && root->right)
        {
            Node *x = root;
            x = x->left;
            // Node* temp=x->left;
            while((x->right)){x=x->right;}
            
            root->data = x->data;
             root->left = deleteFromBst(root->left,x->data);
            return root;
        }
    }
    else if(root->data>val)
    {
        root->left = deleteFromBst(root->left,val);
        return root;
    }
    else
    {
    root->right = deleteFromBst(root->right,val);
        return root;   
    }
}


int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    int arr[]={10,8,9,7,4,11,21,27};
    Node* root = NULL;
    Node* head = NULL;
    buildTree(arr,0,root,head,8);
    preorder(head);
    cout<<endl;
    Node* del = deleteFromBst(head,8);
     preorder(head);
    
    //     10
    //   7   11
    //  6  9   21 
    // 4 7      27
    

    return 0;
}
};