class Solution {
public:

    int maxCount(int start,int i,int cnt[])
    {
        int maxi=0;
       for(int k=0;k<26;k++)
       {
           maxi=max(cnt[k],maxi);
       }
       return maxi;
    }


    int characterReplacement(string s, int k) {
    
             //    abbaba for k=1  
            //   bbab will be the valid longest substring here

            int ans=0;
            int start=0;
            int n=s.size();
            int cnt[26]={}; // all intialised with 0;
             
            for(int i=0;i<n;i++)
            {
                cnt[s[i]-'A']++;
                while(i-start+1 - maxCount(start,i,cnt) > k) //invalid--> valid
                {
                    cnt[s[start]-'A']--;
                    start++;
                }

                //valid 
                ans=max(ans,i-start+1);
            }

            return ans;
    }
};