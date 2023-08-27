#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

 int helper(BinaryTreeNode<int>* root,int &k,int &ans)
    {
       
        if(!root)return 0;
        
        int l = helper(root->left,k,ans);
        --k;
         if(k==0)
        {
            ans =  root->data; 
            return ans;
        }
        int r = helper(root->right,k,ans);
        
        if(l>0 or l<0)
        return l;
        else if(r>0 or r<0)return r;
        else return 0;
    }

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int ans=-1;
    // Write your code here.
    int a =  helper(root,k,ans);
  
    return ans;
}