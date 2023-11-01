
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode()  val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x)  val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode left, TreeNode right)  val(x), left(left), right(right) {}
  };
 
class Solution {
public

    void inorder(TreeNode root,vectorint &ans)
    {
        if(!root)return ;

        inorder(root-left,ans);
        ans.push_back(root-val);
        inorder(root-right,ans);
    }

    vectorint findMode(TreeNode root) {
        vectorint ans,output;
        inorder(root,ans);

         1 2 2  3 3 3 

        int ocnt = 0,currcnt = 0;
        unordered_mapint,int mp;
        for(int i=0;ians.size();i++)
        {
            mp[ans[i]]++;
            currcnt=mp[ans[i]];
            if(currcntocnt)
            {
                ocnt = currcnt;
                output.clear();
                output.push_back(ans[i]);
            }
            else if(currcnt==ocnt)
            {
                output.push_back(ans[i]);
            }
      }
      return output;
    }
};