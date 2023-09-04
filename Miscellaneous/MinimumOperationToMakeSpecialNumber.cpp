class Solution {
public:

    


    int minimumOperations(string nums) {
        
        int n=nums.size();
        unordered_map<char,int> mp;
        if(nums.size()==1 && nums[0]!=0)return 1;
        if(nums.size()==1 && nums[0]==0)return 0;

        for(int i=n-1;i>=0;i--)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                return n-i-2;
            }

            if(nums[i]=='0')
            {
                mp['0']=i;
                mp['5']=i;
            }

            if(nums[i]=='5')
            {
                mp['2']=i;
                mp['7']=i;
            } 
        }
        
        if(mp['0'])
        return n - 1;

        return n;
        

        
    }
};