class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int j=0;
        int ans = 0;
        int prod=1;   
        int n = nums.size();  

        if(k<1)return 0;

        for(int i=0;i<n;i++)
        {
            prod*=nums[i];
            while(j<n && prod>=k)
            {   
                prod/=nums[j];     
                j++;
                if(prod == k && prod==1)break;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};