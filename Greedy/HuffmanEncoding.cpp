//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
public:
  int data;
  Node* left;
  Node* right;
  
  Node(int d)
  {
      this->data = d;
      this->left = NULL;
      this->right = NULL;
  }
    
};

class cmp{
public:  
  bool operator()(Node* &a,Node* &b)
  {
      return a->data > b->data;
  }
};


class Solution
{
    private:
     void preorder(Node* root,string temp,vector<string> &ans)
     {
         if(!root->left && !root->right)
         {
             ans.push_back(temp);
             return ;
         }
         
         preorder(root->left,temp +'0',ans);
         preorder(root->right,temp +'1',ans);
     }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<Node*,vector<Node*>,cmp> pq;
		    
		    for(int i=0;i<N;i++)
		    {
		        Node* n = new Node(f[i]);
		        pq.push(n);
		    }
		    
		    while(pq.size()>1)
		    {
		        Node* l = pq.top();
		        pq.pop();
		        Node* r = pq.top();
		        pq.pop();
		        
		        int d = l->data + r->data;
		        Node* n = new Node(d);
		        n->left = l;
		        n->right = r;
		        pq.push(n);
		    }
		    
		    Node* root = pq.top();
		   
		   vector<string> ans;
		   string temp;
		    preorder(root,temp,ans);
		    return ans;
		    
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends