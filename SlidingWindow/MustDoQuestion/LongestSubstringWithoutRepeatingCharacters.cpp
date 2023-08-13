class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        
        // vector<char> map(128,0);
        int counter=0; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d=0; //the length of substring

        // for() { /* initialize the hash map here */ } 
       unordered_map<char,int> mp;

        while(end<s.size()){

            if(mp[s[end]]>0)
            {
                counter++;
            }
            mp[s[end]]++;
            end++;

            while(counter>0)
            {
                if(mp[s[begin]]>1)
                counter--;

                mp[s[begin]]--;
                begin++;
            }

            d=max(d,end-begin);
        }
        return d;
    }
};


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