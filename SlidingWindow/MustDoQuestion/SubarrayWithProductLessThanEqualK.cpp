class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        


        // 10 4 2 2

        int start=0;
        int end=0;
        long long prod=1;
        int N=nums.size();
        int count =0;
        int ans=0;

        // count=> subarray with product >=K 

        if(k==0)return 0; // important edge case

        while(end<N)
        {
              prod*=nums[end];
                while(start<N && prod>=k)
                {
                   count+=N-end;  // if at any particular prod > k then all the element after the (end)index would make it greater than k only
                    prod/=nums[start];
                    start++;    

                    if(k==1 && prod==1)break;     // important edge case
                }

             end++;
        }

        return (N*(N+1))/2 - count;
        
    }
};