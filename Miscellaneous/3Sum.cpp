class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // [-4 -1 -1 0 1 2]
        // notCompleted
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
    set<vector<int>> st;

        int n=nums.size();
       for(int i=0;i<n;i++)
       {
           int sum=0;
           int temp = nums[i];
           nums.erase(nums.begin() + i);
            sum= -nums[i];
            vector<int> v;

           
             //    twoSum()
                int start=0;
                int end=nums.size()-1;
                while(start<end)
                {
                    if(nums[start]+nums[end]==sum)
                    {
                        v.push_back(temp);
                        v.push_back(nums[start]);
                        v.push_back(nums[end]);
                        sort(v.begin(),v.end());
                        st.insert(v);
                        start++;
                        end--;
                        vector<int> v;
                    }   
                    else if(nums[start]+nums[end]<sum)
                    {
                        start++;
                    }
                    else
                    {
                        end--;
                    }
                }

                if(i!=n-1)
                nums.insert(nums.begin()+i,temp);
                else
                nums.push_back(temp);
       }

    ans.insert(ans.begin(),st.begin(),st.end());

       return ans;
    

         
    }
};