#define ll long long

class Solution {
public:
    string minWindow(string s, string t) {
        
      
        unordered_map<char,ll> mp;
        string ans="";
        
        vector<string> res;
        for(ll i =0;i<t.size();i++)
        {
            mp[t[i]]++;
        }
       
        ll i = 0 ;
        ll j = 0; 
        ll count = mp.size();
        ll minm = INT_MAX;
        string temp="";
        
       while(j<s.size())
       {
           if(mp.find(s[j])!=mp.end())
           {
               mp[s[j]]--;
               if(mp[s[j]]==0)
                   count--;
           }
           temp.push_back(s[j]);

           if(count>0)
           {
               j++;
           }
           if(count==0)
           {
               
               while(count==0)
               {
                   
                   if(mp.find(s[i])!=mp.end())
                   {
                   
               if (j - i + 1 < minm)
                    {
                        minm = j - i + 1;
                        ans = temp;
                    }
                       
                       
                       mp[s[i]]++;
                       if(mp[s[i]]>0)
                           count++;
                   }
                   i++;
                   temp.erase(temp.begin());
                    
               }
               j++;
           }
       }
    return ans;  
    }
    
};