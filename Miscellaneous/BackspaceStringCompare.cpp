class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size()-1;
        int count=0;
        string str1;
        while(n>=0)
        {
            if(s[n]=='#')
                count++;
            else
            {
               if(count>0)
                   count--; 
               else
                   str1+=s[n];
            }
            n--;
        }
        count=0;
        int m = t.size()-1;
        string str2;
          while(m>=0)
        {
            if(t[m]=='#')
                count++;
            else
            {
               if(count>0)
                   count--; 
               else
                   str2+=t[m];
            }
            m--;
        }
        return str1==str2;

    }
};