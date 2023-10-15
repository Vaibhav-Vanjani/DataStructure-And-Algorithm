class Solution {
public:
    bool static cmp(vector<int> a,vector<int> b)
    {
       if(a[0]<b[0])return true;
       return false;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        // return intervals;
        int n=intervals.size();
        int start=intervals[0][0],end=intervals[0][1];
        if(n==1)return {{start,end}};
    vector<vector<int>> ans;
        for(int i=1;i<n;i++)
        {   
            if(end>=intervals[i][0])
            {
                start = min(start,intervals[i][0]);
                end = max(end,intervals[i][1]);
            }
            else
            {
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
      }
        if(ans.empty())
        {
            ans.push_back({start,end});
        }
        else
        {
            vector<int> v=ans.back();
            if(v[0]!=start or v[1]!=end)
            {
                 ans.push_back({start,end});
            }
        }


        return ans;
    }
};