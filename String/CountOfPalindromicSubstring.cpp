class Solution {
public:
    int countSubstrings(string s) {
           int n = s.size();
        if(n<=1)return n;
        int l=0,h=0,cnt=0;
        string temp = "";
        for(int i=1;i<n;i++)
        {
            l = i-1;
            h = i;

            while(l>=0 && h<n && s[l]==s[h])
            {
                cnt++;
                l--;
                h++;
            }
           
             l = i-1;
             h = i+1;

            while(l>=0 && h<n && s[l]==s[h])
            { 
                cnt++;
                l--;
                h++;
            } 
        }

        return cnt+n;
    }
};