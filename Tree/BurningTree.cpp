//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
  void parentMapping(Node* root,unordered_map<Node*,Node*> &mp,Node* &fire,unordered_map<Node*,bool>&visited,int target)
  {
      if(!root)return ;
    //   if(!root->left && !root->right)return;
     
     if(root->data == target)fire = root;
     
     visited[root] = true;
     
      if(root->left)
      {
          mp[root->left] = root;
      }
      if(root->right)
      {
          mp[root->right] = root;
      }
      
      
      parentMapping(root->left,mp,fire,visited,target);
      parentMapping(root->right,mp,fire,visited,target);
  }
  
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        queue<Node*> q;
        
        unordered_map<Node*,Node*> mp;
        unordered_map<Node*,bool> visited;
        Node* fire = NULL;
        parentMapping(root,mp,fire,visited,target);
        
q.push(fire);
    
        int cnt=0;
        
        while(!q.empty())
        {
           int size=q.size();
           
           for(int i=0;i<size;i++)
           {
               Node* fr = q.front();
               q.pop();
               
               visited[fr] = false;
               
               if(mp.find(fr)!=mp.end() && visited[mp[fr]])
               {
                //   visited[m=false;
                // return mp[fr]->data;
                   q.push(mp[fr]);
               }
               
               if(fr->left && visited[fr->left])
              { q.push(fr->left);
              }
               
               if(fr->right && visited[fr->right])
               q.push(fr->right);
           }
           cnt++;
        }
        
        return cnt-1;
        
    }
};


//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends