class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> temp;
        vector<int> mp(101,0);
        for(int i=0;i<target.size();i++)mp[target[i]]=1;
        stack<int> s;
        int popCount=0;

        for(int i=1;i<=target[target.size()-1];i++)
        {
            if(mp[i])
            {
                while(popCount)
                {
                    temp.push_back("Pop");
                    popCount--;
                }
                temp.push_back("Push");
            }
            else 
            {
                popCount++;
                temp.push_back("Push");
            }
                
        }
        return temp;
    
    }
};