class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int l = left.size();
        int r = right.size();
        int minl=0,maxr=n; 
        for(int i=0;i<l;i++)
        {
            minl = max(minl,left[i]);
        }
        for(int i=0;i<r;i++)
        {
            maxr = min(maxr,right[i]);
        }
        return max(n-maxr,minl);
    }
};