class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

       priority_queue<int,vector<int>,greater<int>> maxh;

     for(int i=0;i<nums.size();i++)
     {
       maxh.push(nums[i]);
       if(maxh.size()>k)
       {
           maxh.pop();
       }  
     }
     return maxh.top();

    }
};