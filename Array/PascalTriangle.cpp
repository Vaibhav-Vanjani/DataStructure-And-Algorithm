class Solution {
public
    vectorvectorint generate(int nR) {
        
        vectorvectorint ans;
        if(nR==1)
        {
            ans = {{1}};
            return ans;
        }
        if(nR==2)
        {
            ans = {{1},{1,1}};
            return ans;
        }
        
        ans = {{1},{1,1}};
        for(int k = 3;k=nR;k++)
        {
            int n = ans.size();

            vectorint temp;
            temp.push_back(1);
            for(int i=0;ians[n-1].size()-1;i++)
            {
                temp.push_back(ans[n-1][i]+ans[n-1][i+1]);
            }
            temp.push_back(1);
            
            ans.push_back(temp);
            temp.clear();
        }

        return ans;

    }
};