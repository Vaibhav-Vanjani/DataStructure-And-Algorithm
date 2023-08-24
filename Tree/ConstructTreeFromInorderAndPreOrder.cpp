//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    Node* helper(int is,int ie,int &idx,int in[],int pre[],unordered_map<int,int> &mp,int n)
    {
        if(is>ie or (idx>(n-1)))return NULL;
         
           
        int pos;
        for(int i=is;i<=ie;i++)
        {
            if(in[i]==pre[idx])
            {
                pos = i;
                break;
            }
        }
         int ele = pre[idx++];    
        Node* root = new Node(ele);
        
        
        
        root->left = helper(is,pos-1,idx,in,pre,mp,n);
        root->right = helper(pos+1,ie,idx,in,pre,mp,n);
        
        return root;
    }
    
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[in[i]] = i;
        }
        int idx=0;
        return helper(0,n-1,idx,in,pre,mp,n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends