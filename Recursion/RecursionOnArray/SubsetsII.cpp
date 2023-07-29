class Solution {
public:

   void helper(int j,vector<int> nums,int n,vector<int> temp,vector<vector<int>> &output)
    {
         output.push_back(temp);
        // if(j==n)
        // return ;   
       for(int i=j;i<n;i++)
       {
           if(i>j && nums[i]==nums[i-1])
           continue;

            temp.push_back(nums[i]);
            helper(i+1,nums,n,temp,output);
            temp.pop_back();
       }
       
} 

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int i=0;
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> output,ans;
        sort(nums.begin(),nums.end());
        helper(0,nums,n,temp,output);
        return output;
    }
};