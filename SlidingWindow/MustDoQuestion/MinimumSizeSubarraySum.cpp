class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int mini = INT_MAX;
        int ans = 0;
        int i=0;
        int j=0;
        int n=nums.size();
       int sum=0;

        while(j<n)
        {
            sum+=nums[j];

                while(target<=sum)
                {
                    ans = j-i+1;
                    if(ans<mini)
                    {
                        mini = ans;
                    }
                    sum-=nums[i];
                    i++;
                    // return sum;
                }
           
            j++;
        }
        return mini==INT_MAX?0:mini;
    }
};