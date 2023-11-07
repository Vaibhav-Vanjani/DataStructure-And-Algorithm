class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        int n = dist.size();
        int m = speed.size();
        vector<double> pp;
        for(int i=0;i<n;i++)
        {
            pp.push_back(((double)dist[i]/(double)speed[i]));
        }
      
        sort(pp.begin(),pp.end());
        int x = pp.size();
        int elimination=1;
        for(int i=1;i<n;i++)
        {
            pp[i] = pp[i]-(double)i;
            if(pp[i]<=0)return elimination;
            elimination++;
        }
        return n;

        // 1 1 1 1 2


    }
};