//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends




/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

Node* helper(int &idx,int is,int ie,int in[],int post[],int n)
{
    if(is>ie || idx<0)return NULL;
   
    int ele = post[idx]; 
    int pos =-1;
    for(int i=is;i<=ie;i++)
    {
        if(in[i]==ele)
        {pos=i;break;}
    }
    idx--;
    
    if(pos==-1)return NULL;
    
    Node* root = new Node(ele);
    
    root->right = helper(idx,pos+1,ie,in,post,n);
    root->left = helper(idx,is,pos-1,in,post,n);
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int idx = n-1;
   return helper(idx,0,n-1,in,post,n);
}
