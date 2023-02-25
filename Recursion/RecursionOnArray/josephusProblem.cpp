class Solution {
public:

    int helper(vector<int> ans,int n,int k,int i)
    {
        if(n==1)return ans[0];

        int z = i+k-1;
        z= z>=n ? z%n : z ;
        ans.erase(ans.begin() + z);
        
        return helper(ans,n-1,k,z);
    }



    int findTheWinner(int n, int k) {
        
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=i+1;
        }

        return helper(ans,n,k,0);


    }
};