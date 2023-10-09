class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        if(n<=1)return s;
        int a=0,b=1,l=0,h=0,len=1,existing=-1,start=0;
        for(int i=1;i<n;i++)
        {
            l = i-1;
            h = i;

            while(l>=0 && h<n && s[l]==s[h])
            {
                if( (h-l+1) > len)
                {
                    start = l;
                    len = h-l+1;
                }

                l--;
                h++;
            }

             l = i-1;
             h = i+1;

            while(l>=0 && h<n && s[l]==s[h])
            {
                if(h-l+1 > len)
                {
                    start = l;
                    len = h-l+1;
                }

                l--;
                h++;
            }

            if(len>existing)
            {
                a=start;
                b=len;
                existing = len;
            }   
            len=0;     

        }

        return s.substr(a,b);
    }
};