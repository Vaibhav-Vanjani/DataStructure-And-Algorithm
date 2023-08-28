/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* node) {
           //Your code here
      queue<Node*> q;
      if(node)q.push(node);
      
      vector<int> ans;
      
      while(!q.empty())
      {
          int size =  q.size();
          for(int i=0;i<size;i++)
          {
              Node* x = q.front();
              q.pop();

              if(i==(size-1))x->next=NULL;
              else x->next = q.front();
              
              if(x->left)
              q.push(x->left);
              
              if(x->right)
              q.push(x->right);
              
            //   ans.push_back(x->data);
          }
      }
      return node;
    }

};