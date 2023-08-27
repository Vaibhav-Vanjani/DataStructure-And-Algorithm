/************************************************************
    Following is the Binary Search Tree node structure

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

************************************************************/


TreeNode* helper(TreeNode* root,int minl,int maxl,TreeNode* l,TreeNode* r)
{
    if(!root)return NULL;

    if(root->data>=minl && root->data<=maxl)
    {
        return root;
    }
    else if(root->data>minl && root->data>maxl)
    l = helper(root->left,minl,maxl,l,r);
    else if(root->data<minl && root->data<maxl)
    r = helper(root->right,minl,maxl,l,r);
    
    if(l)return l;
    else if(r)return r;
    else return NULL;
}


TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    int minl = min(P->data,Q->data);
    int maxl = max(P->data,Q->data);

    return helper(root,minl,maxl,NULL,NULL);
    
}