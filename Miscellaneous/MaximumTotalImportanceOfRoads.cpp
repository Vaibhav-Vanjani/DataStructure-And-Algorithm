class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
       
 //to have freq of each city in road
    long long cnt[50001] = {}, res = 0;
    for (auto &r : roads) {
        ++cnt[r[0]];
        ++cnt[r[1]];
    }

    //to sort till n
   sort(cnt,cnt + n);
  
  //highest freq will be with n-1 element 
    for (int i = 0; i < n; ++i)
        res += cnt[i] * (i + 1);

        
    return res;        




    }
};