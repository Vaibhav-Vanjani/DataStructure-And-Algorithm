class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // tc -> O(N)
        // SC -> O(1)

        int exor = 0;
        for(int i=0;i<nums.size();i++)
        {
            exor^=nums[i];
        }
        return exor;
    }
};