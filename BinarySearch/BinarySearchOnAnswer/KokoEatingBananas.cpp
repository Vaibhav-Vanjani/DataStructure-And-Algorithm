class Solution {
public:

    // Edge case:
    //here in this whenever dividing check if divide by zero condition can occur
    // integer overflow 

    bool isValid(int mid,vector<int> piles, int h)
    {


        int hour =0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]<mid)
            hour++;
            else
            hour += ( piles[i] % mid )!=0 ?  (piles[i]/mid)+1 : (piles[i]/mid) ;

            // int temp = piles[i];
            // while(temp)
            // {
            //     if(temp<mid)
            //     {
            //         temp=0;
            //         hour++;
            //     }
            //     else
            //     {
            //         temp-=mid;
            //         hour++;
            //     }
            // }

            if(hour>h)
            return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        

        long long start=0;
        long long sum=0;
        int n =piles.size();
        
        for(int i=0;i<n;i++)
        sum+=piles[i];
        
         long long end=sum;
        long long ans=0;
         while(start<=end)
         {
            long long mid = start + (end-start)/2;

            if(mid!=0 && isValid(mid,piles,h) )
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
         }
         return ans;

    }
};