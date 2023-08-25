class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26,0);
        int n = s.size();
        int maxi = 0;
        int idx;
       // get char index of most frequency 
            for(int i=0;i<n;i++)
            {
                cnt[s[i]-'a']++;
                if(cnt[s[i]-'a']>maxi)
                {
                    maxi = cnt[s[i]-'a'];
                    idx = s[i]-'a';
                }
            }

        // checking for invalid string 
        if((2*cnt[idx]-1) > n)return "";

        // even index filling with most frequency element 
        int i = 0;
        while(cnt[idx])
        {
            s[i]=idx+'a';
            i+=2;
            --cnt[idx];
        }

        // odd index filling 
        for(int j=0;j<26;j++)
        {
            while(cnt[j])
            {
                if(i>=n)i=1;

                s[i]=j+'a';
                i+=2;
                cnt[j]--;
            }
        }

        return s;
    }
};