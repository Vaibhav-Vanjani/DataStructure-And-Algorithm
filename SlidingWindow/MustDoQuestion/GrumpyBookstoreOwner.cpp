
Sliding window maximum Variation
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int start =0;
        int end=0;
        int N =customers.size();
        int sum=0;
        int prevSum =0;
        while(end<N)
        {
            if(grumpy[end]==1)
            {
                sum+=customers[end];
            }

            if(end-start+1 < minutes)
            {
                end++;
            }
            else if(end-start+1 == minutes)
            {
                if(sum>prevSum)
                {
                    prevSum = sum ;
                }

                if(grumpy[start]==1)
                sum-=customers[start];
                
                start++;
                end++;
            }

        }

        for(int i=0;i<N;i++)
        {
              if(grumpy[i]==0)
                {
                prevSum+=customers[i];
                }
        }
        return prevSum;
    }
};