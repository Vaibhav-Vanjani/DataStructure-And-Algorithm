class Solution {
public:
    int maxRepOpt1(string txt) {
        
        unordered_map<char,vector<int>> mp;
        int n =txt.size();
        for(int i=0;i<n;i++)
        mp[txt[i]].push_back(i);

        int res=1;
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            vector<int> v;
            v= it->second;
            int n = v.size();
            int cur =1;
            int pre=0;
            int maxi=0;

            for(int i=1;i<n;i++)
            {
                if(v[i]==v[i-1]+1)
                cur++;
                else
                {
                    pre = v[i]==v[i-1]+2 ? cur : 0;
                    cur=1;
                }
                maxi = max(maxi,cur+pre);
            }
 
            res = max(res, maxi<n ? maxi+1 : maxi);
        }
      
    return res;
    }
};