class Solution {
public:

   long helper(int idx,string s,int n,unordered_map<string,int> &mp,int dp[])
    { 
        if(idx>=n)
        return 0;

        if(dp[idx]!=-1)return dp[idx];

        string b = "";   
        long ans = n;    
        for(int i = idx;i<n;i++)
        {
            b+=s[i];
            long l = mp[b] ? 0 : b.size();
            l+=helper(i+1,s,n,mp,dp);
            ans = min(l,ans); 
         
          // b.erase(b.begin()+b.size()-1);
        }

        return dp[idx] = ans;
    }


    int minExtraChar(string s, vector<string>& dictionary) {

        int n = s.size();
          int m = dictionary.size();
        // vector<string> allSubs;
        unordered_map<string,int> mp;
        
       for(int i=0;i<m;i++)
       {
         mp[dictionary[i]]++;
       }
        long ans = n;
        int dp[51];
        memset(dp,-1,sizeof(dp));
        return helper(0,s,n,mp,dp);

    }
};