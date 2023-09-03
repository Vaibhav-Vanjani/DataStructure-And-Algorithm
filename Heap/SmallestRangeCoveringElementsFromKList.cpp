class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int n = nums.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                temp.push_back({nums[i][j],i});
            }
        }
        int k = n;
        sort(temp.begin(),temp.end());

        int i=0;
        int j=0;
        n=temp.size();
        unordered_map<int,int> mp;
        vector<int> res(2,0);
        int count=0;
        int ans = INT_MAX;

        while(j<n)
        {   
            mp[temp[j].second]++;
            if(mp[temp[j].second]==1)
            {
                count++;
            }

           
           if(count==k)
            {
                if( (temp[j].first - temp[i].first) < ans )
                {
                     ans = (temp[j].first - temp[i].first);
                    res[0] = temp[i].first;
                    res[1] = temp[j].first;   
                }

                while(count == k)
                {
                    mp[temp[i].second]--;
                    
                   
                    if(mp[temp[i].second]==0)
                    {count--;i++;}
                    else
                    {
                        i++;
                         if( (temp[j].first - temp[i].first) < ans )
                        {
                            ans = (temp[j].first - temp[i].first);
                            res[0] = temp[i].first;
                            res[1] = temp[j].first;   
                        }
                    }

                    
                }
            }
            j++;
        }

        return res;




    }
};