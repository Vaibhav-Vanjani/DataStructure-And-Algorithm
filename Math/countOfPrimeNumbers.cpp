class Solution {
public:
    int countPrimes(int n) {
        

        // vector<worstcase time complexity > is better(lesser) than map<worstcase time complexity>;
        // complexity O(n*log(log(n)))
        
	vector<int> mp(n+1,1);
        int count = 0;
        for(int i=2;i<n;i++)
        {
            if(mp[i])
            {
              count++; 
               for(int j = i*2 ;j<n ; j+=i)
               {
                       mp[j]=0;  
               }
            }
        }


        
        
        
        return count;

    }
};