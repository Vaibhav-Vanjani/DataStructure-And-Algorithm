class Solution {
public:


    void helper(vector<string> ans,int i,int n,int j,string temp,vector<string> &output)
    {
        if(i==n)
        {
            output.push_back(temp);
            return ;
        }

        int size = ans[i].size();

        for(int k=j; k<size; k++)
        {
            temp.push_back(ans[i][k]);
            helper(ans,i+1,n,j,temp,output);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        int n = digits.size();
        if(n==0)
        {
            vector<string> ans;
            return ans;
        }

     map<char,string> mp;
       mp['2']="abc";
       mp['3']="def";
       mp['4']="ghi";
       mp['5']="jkl";
       mp['6']="mno";
       mp['7']="pqrs";
       mp['8']="tuv";
       mp['9']="wxyz";

       vector<string> ans;
        for(int i=0;i<n;i++)
        {   
            ans.push_back(mp[digits[i]]);
        }

        int i=0;  // for no. of digits
        int j=0; // for looping
        string temp;
        vector<string> output;
        helper(ans,i,n,j,temp,output);
        return output;
    }
};