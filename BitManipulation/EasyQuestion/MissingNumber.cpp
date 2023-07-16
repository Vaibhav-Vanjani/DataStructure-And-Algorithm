class Solution {
public:
    int missingNumber(vector<int>& nums) {
        

        long long exor = nums.size(); 
        for(int i=0;i<nums.size();i++)
        {
             exor^=i;
             exor^=nums[i];
        }
        
        return exor;


    }
};