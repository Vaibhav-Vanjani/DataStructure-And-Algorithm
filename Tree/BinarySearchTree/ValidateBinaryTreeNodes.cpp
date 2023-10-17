class Solution {
public:

    long long cntr(vector<int>& l, vector<int> &r,long long root,int dp[])
    {
        if(root==-1)return 0;
        if(dp[root]!=-1)return dp[root];
        return dp[root] = 1+cntr(l,r,l[root],dp)+cntr(l,r,r[root],dp);
    }


    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        

        vector<int> indegree(n,0);

        // checking for indegree>1
        // that is pointing to child more than 1 time 
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1 && indegree[leftChild[i]]++==1)return false;
            if(rightChild[i]!=-1 && indegree[rightChild[i]]++==1)return false;
        } 
     
        int cnt=0; 
        long long root=-1;       
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                cnt++;
                root=i;
            }
        }

        if(cnt==0 or cnt>1)return false;

        int dp[10001];
        memset(dp,-1,sizeof(dp));
        return cntr(leftChild,rightChild,root,dp)==n;


    }
};


//revisit
class Solution {
    int helper(int root,vector<int>& left, vector<int>& right,int dp[])
    {
        if(root==-1)return 0;
        
        if(!dp[root])dp[root]=1;
        else return 1;

        return 1 + helper(left[root],left,right,dp) + helper(right[root],left,right,dp);
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
    
       unordered_map<int,int> indegree;
       for(int i=0;i<n;i++)
           indegree[left[i]]++;
       
       for(int i=0;i<n;i++)
           indegree[right[i]]++;

       int cnt=0;
       int root = 0;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]>1)return false;
            if(indegree[i]==0){root = i;cnt++;}
        }
        if(cnt>1 or cnt==0)return false;
        int dp[n];
        memset(dp,0,sizeof(dp));
        return helper(root,left,right,dp)==n;

    }
};	