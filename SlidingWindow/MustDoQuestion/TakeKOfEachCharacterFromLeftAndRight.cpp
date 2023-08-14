class Solution {
public:
    int takeCharacters(string s, int k) {
        
      unordered_map<char,int> countMap;
      
      int n =s.size();
      for(int i=0;i<n;i++)
      countMap[s[i]]++;

      if(countMap['a']<k or countMap['b']<k or countMap['c']<k)
      return -1;
     
      int ans=INT_MAX;
      int window=0;

      int j=0;  
      for(int i=0;i<n;i++)
      {
          countMap[s[i]]--;
          window++;

          while(countMap[s[i]]<k)
          {
              countMap[s[j]]++;
              j++;

              window--;
          }

          ans=min(ans,n-window);
      }
      return ans;



    }
};
--------------------------------------------------
class Solution {
public:
    int takeCharacters(string s, int k) {
        
      unordered_map<char,int> countMap;
      
      int n =s.size();
      for(int i=0;i<n;i++)
      countMap[s[i]]++;

      if(countMap['a']<k or countMap['b']<k or countMap['c']<k)
      return -1;
     
      int ans=INT_MAX;
      int window=0;

      int j=0;  
      for(int i=0;i<n;i++)
      {
          countMap[s[i]]--;
          window++;

          while(countMap[s[i]]<k)
          {
              countMap[s[j]]++;
              j++;

              window--;
          }

          ans=min(ans,n-window);
      }
      return ans;



    }
};