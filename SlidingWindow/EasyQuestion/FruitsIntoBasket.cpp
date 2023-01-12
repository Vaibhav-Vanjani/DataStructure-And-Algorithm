
// question based longest substring with k unique characters

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int N= fruits.size();
        int end=0;
        int start=0;
        unordered_map<int,int> mp;
        int count=0;
        int maximumFruits=0;

        while(end<N)
        {
            mp[fruits[end]]++;
            if(mp[fruits[end]]==1)
            count++;

            if(count<2)
            {
                maximumFruits=max(maximumFruits,end-start+1); 
                end++;
            }
            else if(count==2)
            {
                maximumFruits=max(maximumFruits,end-start+1);
                end++;
            }
            else if(count>2)
            {
                while(count>2)
                {
                    mp[fruits[start]]--;
                    if(mp[fruits[start]]==0)
                    count--;

                    start++;
                }
                maximumFruits = max(maximumFruits,end-start+1);
                end++;
            }
        }
        return maximumFruits;

    }
};