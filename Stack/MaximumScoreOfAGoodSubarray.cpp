class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        int res = INT_MIN;
        stack<pair<int,int>> s;
        int rightMin[n],leftMin[n];
        leftMin[0]=-1;
        s.push({nums[0],0});
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]>s.top().first)
            {
                leftMin[i]=s.top().second;    
            }
            else
            {
                while(!s.empty() && s.top().first>=nums[i])
                s.pop();

                if(s.empty())
                {
                    leftMin[i]=-1;
                }
                else
                {
                    leftMin[i]=s.top().second;
                }
            }
            s.push({nums[i],i});
        }

        
      stack<pair<int,int>> st;

        rightMin[n-1]=n;
       st.push({nums[n-1],n-1});
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>st.top().first)
            {
                rightMin[i]=st.top().second;    
            }
            else
            {
                while(!st.empty() && st.top().first>=nums[i])
                st.pop();

                if(st.empty())
                {
                    rightMin[i]=n;
                }
                else
                {
                    rightMin[i]=st.top().second;
                }
            }
            st.push({nums[i],i});
        }

        for(int i=0;i<n;i++)
        {
            if(leftMin[i]<k && rightMin[i]>k) 
            {
                res = max(res,nums[i]*(rightMin[i]-leftMin[i]-1));
            }
        }
        
        return res;
    }
};