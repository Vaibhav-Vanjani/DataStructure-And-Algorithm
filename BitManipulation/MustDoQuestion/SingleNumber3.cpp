class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int exor=0;
        for(int i=0;i<nums.size();i++)
        {
            exor^=nums[i];
        }

        int getRightMostSetBit=0;
        for(int i=0;i<=31;i++)
        {
            if(exor&(1<<i)){
            getRightMostSetBit=i;
            break;}
        }

        int x=0;
        int y=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&(1<<getRightMostSetBit))
            x^=nums[i];
            else
            y^=nums[i];
        }

        vector<int> ans;
        ans.push_back(x);
        ans.push_back(y);
        return ans;
  
    }
};