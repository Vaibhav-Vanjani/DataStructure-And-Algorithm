class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    if(s.size()==1 or s.size()==0)
    return s.size();

//Sliding Window Approach

     unordered_map<char,int> mp;
     int uniqueCount = 0;

     int start =0;
     int end =0;
     int N=s.size();
int maxiLength=-1;
     while(end<N)
     {
         mp[s[end]]++;
        if(mp[s[end]]==1)
        uniqueCount++;

        if(uniqueCount<end-start+1)
        {
          while(uniqueCount<end-start+1)
          {
              mp[s[start]]--;
              if(mp[s[start]]==0)
              uniqueCount--;
              start++;
          }
           maxiLength = max(uniqueCount,maxiLength);
        }
        else if(uniqueCount==(end-start+1))
        maxiLength = max(uniqueCount,maxiLength);
        
        end++;
     }

     return maxiLength;
    }
};