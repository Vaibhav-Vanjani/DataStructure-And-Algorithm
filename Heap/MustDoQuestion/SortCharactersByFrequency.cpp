class Solution {
public:
    string frequencySort(string s) {
        
        //get frequency of each char
        unordered_map<char,int> mp;
        for(auto ele:s)
        {
            mp[ele]++;
        }
        //push with frequency
        priority_queue<pair<int,char>> maxh;
        for(auto it:mp)
        {
            maxh.push({it.second,it.first});
        }
        //push into answer
        string answer;
        while(maxh.size())
        {
            char top = maxh.top().second;
            int count = maxh.top().first;
            while(count)
            {
                answer+=top;
                count--;
            }
            maxh.pop();
        }
        return answer;
    }
};