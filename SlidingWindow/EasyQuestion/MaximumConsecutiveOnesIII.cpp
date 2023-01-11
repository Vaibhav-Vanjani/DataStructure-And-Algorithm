class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int start =0;
        int end =0;
        int N = nums.size();
        int countOfZero = 0;
        int maximumLength=0;
        while(end<N)
        {
               if(nums[end]==0)
                countOfZero++;

            if(countOfZero<k)
            {
                maximumLength = max(maximumLength,end-start+1);
                end++;
            }
            else if(countOfZero==k)
            {
                maximumLength = max(maximumLength,end-start+1);
                end++;
            }
            else if(countOfZero>k)
            {
                while(countOfZero>k)
                {
                    if(nums[start]==0)
                    countOfZero--;
                    
                    start++;
                }
                end++;
            }
        }
return maximumLength;

    }
};