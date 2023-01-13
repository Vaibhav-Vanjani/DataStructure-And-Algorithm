class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        


        int start=0;
        int end=0;
        string txt;
        unordered_map<string,int> mp;
        vector<string> answer;
        int N = s.size();
        if(N<10)
        return answer;

        while(end<N)
        {
            txt+=s[end];

            if(txt.size()<10)
            end++;
            if(txt.size()==10)
            {
                if(!mp[txt])
                mp[txt]=1;
                else
                {
                    if(mp[txt]==1)
                    answer.push_back(txt);

                    mp[txt]++;
                }

                txt.erase(txt.begin());

                start++;
                end++;
            }

        }
        return answer;
    }
};