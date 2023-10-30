class Solution {
public:

    bool static cmp(pair<int,int> a,pair<int,int> b)
    {
        if(a.first<b.first)return true;
        else if(a.first==b.first && a.second<b.second)return true;
        return false; 
    }

    vector<int> sortByBits(vector<int>& arr) {
        
        int n = arr.size();
        vector<pair<int,int>> mp;
        for(int i=0;i<n;i++)
        {
            int num = arr[i];
            int one = 0;
            while(num)
            {
                if(num%2!=0)
                    one++;
                num>>=1;
            }
            mp.push_back({one,arr[i]});
        }

        vector<int> ans(n,0);
       sort(mp.begin(),mp.end(),cmp);

        for(int i=0;i<n;i++)
        {
            ans[i]=mp[i].second;
        }

        return ans;
    }
};