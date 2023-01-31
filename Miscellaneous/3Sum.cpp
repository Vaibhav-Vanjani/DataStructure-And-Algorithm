class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
  //Learning:

	//1 . if you write vector<int> v after putting some elements it doesnt reinitialises it 
	//    rather you should use  v.clear() for erasing all elements
	//2 . in  sum i had written sum = -nums[i] which i had erased in previous line

     // Pay attention to what you have written earlier


        // [-4 -1 -1 0 1 2]
    //   Completed

        sort(nums.begin(),nums.end()); //for 2 sum sorted array is needed
        vector<vector<int>> ans;
        set<vector<int>> st;

        int n=nums.size();
       for(int i=0;i<n;i++)
       {
           int sum=0;
           int temp = nums[i];
           nums.erase(nums.begin() + i);
            sum= -temp;
            vector<int> v;

           
             // ----- twoSum()-----

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
                       v.clear();
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

		// ----twoSum() over---

                if(i!=n-1)
                nums.insert(nums.begin()+i,temp);
                else
                nums.push_back(temp);
       }

    ans.insert(ans.begin(),st.begin(),st.end());

       return ans;
    

         
    }
};