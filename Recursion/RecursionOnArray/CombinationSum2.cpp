class Solution {
public:

    void helper(int i,int sum,vector<int> temp,vector<int> candidates, int target,vector<vector<int>> &output)
    {

        if(sum == target)
        {
            output.push_back(temp);
            return;
        }

       
    
        for(int j=i;j<candidates.size();j++)
        {
            if(j>i and candidates[j]==candidates[j-1])
            continue;

             if(sum>target)
             break;

                temp.push_back(candidates[j]);
                helper(j+1,sum+candidates[j],temp,candidates,target,output);
                temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int sum=0;
        vector<int> temp;
        vector<vector<int>> output;
        
        sort(candidates.begin(),candidates.end());

        helper(0,sum,temp,candidates,target,output);

        // set<vector<int>> s;
        // for(int i=0;i<output.size();i++)
        // {
        //     sort(output[i].begin(),output[i].end());
        //     s.insert(output[i]);
        // }

        // vector<vector<int>> unique_op;

        // for(auto it:s)
        // {
        //     unique_op.push_back(it);
        // }
        return output;
    }
};