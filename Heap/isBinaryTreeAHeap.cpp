//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool isHeap(struct Node* node) {
        // code here
        
        queue<Node*> q;
      if(node)q.push(node);
      
      bool flag = false;
      
      vector<int> ans;
      
      while(!q.empty())
      {
          for(int i=0;i<q.size();i++)
          {
              Node* x = q.front();
              q.pop();
              
              if(!x->left and x->right)return false;
              
              if(x->left)
              {
                  if(flag)return false;
                  
                  q.push(x->left);
              }
              
              if(x->right)
                 {
                  if(flag)return false;
                  
                  q.push(x->right);
              }
              
              if(!x->left or !x->right)flag = true;
              
              ans.push_back(x->data);
          }
      }
      
      int n = ans.size();
      int l;
      int r;
      
      for(int i =0;i<n/2;i++)
      {
          l=2*i+1;
          r=2*i+2;
          
          if((l<n && ans[i]<ans[l]) or (r<n && ans[i]<ans[r]))
          return false;
          
      }
      return true;
      
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends