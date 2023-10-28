class Solution {
public:
    int countVowelPermutation(int n) {

        if(n==1)return 5;   
        vector<long long> freq(5,0);
        vector<long long> choice(5,0);
        choice[0]=1;
        choice[1]=1;
        choice[2]=1;
        choice[3]=1;
        choice[4]=1;
            
        int mod = 1e9+7,ans=5;    
        for(int i=2;i<=n;i++)
        {
            freq[0]=choice[1]%mod+choice[2]%mod+choice[4]%mod;
            freq[1]=choice[0]%mod+choice[2]%mod;
            freq[2]=choice[1]%mod+choice[3]%mod;
            freq[3]=choice[2]%mod;
            freq[4]=choice[3]%mod+choice[2]%mod;

            choice[0]=freq[0]%mod;
            choice[1]=freq[1]%mod;
            choice[2]=freq[2]%mod;
            choice[3]=freq[3]%mod;
            choice[4]=freq[4]%mod;
            
            ans=(choice[0]%mod+choice[1]%mod+choice[2]%mod+choice[3]%mod+choice[4]%mod)%mod;
        }
        return ans;
    }
};