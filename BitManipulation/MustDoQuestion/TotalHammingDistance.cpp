class Solution {
public:


    int totalHammingDistance(vector<int>& nums) {
 vector<int> storesNumberOfOnes(32,0);
    for(int i=0;i<=31;i++)
    {
        int mask = 1<<i;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]&mask)
            storesNumberOfOnes[i]++;
        }
    }

    int sum=0;
    for(int i=0;i<32;i++)
    {
         if(storesNumberOfOnes[i])
         {
             int a = nums.size()-storesNumberOfOnes[i]; //number of zeroes
             int b = storesNumberOfOnes[i]; //number of ones
             int ans = a*b; // total combination of (1,0)
             sum+=ans;
         }
    }

    return sum;    }
};