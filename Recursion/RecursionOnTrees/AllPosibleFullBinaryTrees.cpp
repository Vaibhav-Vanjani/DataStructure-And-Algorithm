class Solution {
public:

    // full binary tree has a property which is it has odd no. of nodes.
    // even no. of nodes can never make a full binary tree.

    // unordered_map<int,vector<TreeNode*>> mp;

    vector<TreeNode*> allPossibleFBT(int n) {

                vector<TreeNode*> ans;
                if (n < 1 || n % 2 == 0) {
                    // if n is less than 1 or a multiple of 2: cannot have a FULL binary tree
                    return ans;
                }
                if(n==1)
                {
                    TreeNode* root = new TreeNode(0);
                    ans.push_back(root);
                    // mp[1]=ans;
                    return ans;
                }

                // if(mp.find(n)!=mp.end())return mp[n];

                for(int k=1;k<n;k+=2)
                {
                    vector<TreeNode*> leftAns = allPossibleFBT(k);
                    vector<TreeNode*> RightAns = allPossibleFBT(n-k-1);

                        for(int i=0;i<leftAns.size();i++)
                        {
                            for(int j=0;j<RightAns.size();j++)
                            {
                                TreeNode* root = new TreeNode(0);
                                root->left = leftAns[i];
                                root->right = RightAns[j];
                                 ans.push_back(root);
                            }
                           
                        }
                }
                // mp[n]=ans;
                return ans;
    }
};