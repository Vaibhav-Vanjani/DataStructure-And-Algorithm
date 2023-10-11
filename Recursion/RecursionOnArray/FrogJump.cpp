class Solution {

    int helper(vector<int> &stones,int k,int indx,int n,unordered_map<int,int> &mp,int &maxm,map<pair<int,int>,int> &dp)
    {
        if(mp[indx]==n)return 2;
        if(!mp[indx] or indx>maxm)return 1;

        if(dp[{k,indx}])return dp[{k,indx}];
        
        if(k==1)
        {
            return dp[{k,indx}] = max(helper(stones,k,indx+k,n,mp,maxm,dp) , helper(stones,k+1,indx+k+1,n,mp,maxm,dp));
        }
        else
        {
            return dp[{k,indx}] = max(helper(stones,k-1,indx+k-1,n,mp,maxm,dp),max(helper(stones,k,indx+k,n,mp,maxm,dp) , helper(stones,k+1,indx+k+1,n,mp,maxm,dp)));
        }
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n<=1)return true;
        if(n>=2 && stones[1]!=1)return false;

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[stones[i]]=i+1;
           
        }
         int maxm = stones[n-1];
       map<pair<int,int>,int> dp;

        int k = 1;
        int indx = 1;
       int a =  helper(stones,k,indx,n,mp,maxm,dp);
       return a==2;
    }
};