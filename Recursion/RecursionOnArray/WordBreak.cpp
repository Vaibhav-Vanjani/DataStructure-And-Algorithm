class Solution {

    int solve(int indx,int n,string str,unordered_map<string,int> &mp,string s,int dp[])
    {
        if(indx==n && str=="")return 1;
        if(indx==n && str!="")return 0;
        
        if(dp[indx]!=-1)return dp[indx];

        str=""; 
        for(int i=indx;i<n;i++)
        {
            str+=s[i];
            if(mp[str])
            {
                if(solve(i+1,n,"",mp,s,dp)==1)return dp[indx] = 1;
            }
        }
        return dp[indx]=0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
       unordered_map<string,int> mp;
       string str;
       int dp[301];
       memset(dp,-1,sizeof(dp));
        int n = s.size();
        int m = wordDict.size();
        for(int i=0;i<m;i++)
        {
            mp[wordDict[i]]=1;
        }
       return solve(0,n,str,mp,s,dp)==1;
    }
};