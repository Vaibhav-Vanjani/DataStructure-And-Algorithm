class Solution {
public:

    bool isPalindrome(string s)
    {
        int size = s.size();
        int i = 0;
        int j = size-1;

        while(i<j)
        {
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }

    void helper(string s,int i,int n,vector<string> temp,vector<vector<string>> &output)
    {
        if(i==n)
        {
            output.push_back(temp);
            return ;
        }

        string str = "";
        for(int j=i;j<n;j++)
        {
            str+=s[j];
            if(isPalindrome(str))
            {
                temp.push_back(str);
                helper(s,j+1,n,temp,output);
                temp.pop_back();
            }
        }

    }



    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> output;
        vector<string> temp;
        int i=0;
        int n = s.size();
        helper(s,i,n,temp,output);
        return output;
    }
};