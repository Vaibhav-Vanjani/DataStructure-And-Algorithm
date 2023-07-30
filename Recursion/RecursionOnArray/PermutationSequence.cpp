class Solution {
public:

    int ceil(int a,int b)
    {
        if(a%b == 0)return a/b;
        else return a/b+1;
    }

    string getPermutation(int n, int k) {
        

        vector<int> mp;
        int fact = 1;

        for(int i=1;i<=n;i++)
        {
            mp.push_back(i);
            fact*=i;
        }
        int size = mp.size();
        fact=fact/n;

        string ans="";

        while(n>=1)
        {
            int temp = ceil(k,fact);
            ans += to_string(mp[temp-1]);

            mp.erase(mp.begin() + temp-1);
            n = n-1;
            k = k%fact;

            if(!k or !n)break;
            fact = fact/n;
        }

        if(!k or !n)
    {        
        for(int i=mp.size()-1;i>=0;i--)
        ans += to_string(mp[i]);
    }
        return ans;



    }
};