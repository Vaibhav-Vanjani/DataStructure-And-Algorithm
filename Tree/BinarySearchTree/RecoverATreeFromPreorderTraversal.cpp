/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    


    TreeNode* recoverFromPreorder(string traversal) {
    
       int n = traversal.size();
       int i=0;
       string num="";
        while(i<n && traversal[i]!='-')
         { num+=traversal[i];
              i++;}
       TreeNode* root = new TreeNode(stoi(num));
       unordered_map<int,TreeNode*> mp;
       mp[0] = root;
       TreeNode* ans = root; 
       int cnt=0;
        while(i<n)
        {
            if(traversal[i]=='-')
           { cnt++;i++;}
            else 
            {
             num="";  
               while(i<n && traversal[i]!='-')
              { num+=traversal[i];
              i++;}

            //  if(cnt==0)break;
                
                if(!(mp[cnt-1]->left))
                {
                    mp[cnt-1]->left = new TreeNode(stoi(num));
                    mp[cnt] = mp[cnt-1]->left;
                }
                else
                {
                    mp[cnt-1]->right = new TreeNode(stoi(num));
                    mp[cnt] = mp[cnt-1]->right;
                } 
                cnt=0;
            }
          
        }
        return ans;     
    }
};