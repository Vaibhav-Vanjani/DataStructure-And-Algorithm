class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
            vector<int> arr = pref;
            int n = arr.size();
            for(int i=1;i<n;i++)
            {
                arr[i] = pref[i]^pref[i-1];
            }
            return arr;
    }
};