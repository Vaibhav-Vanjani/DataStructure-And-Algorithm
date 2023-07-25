class Solution {
public:

    int ceil(int a , int b)
    {
        if(a <= b)return 1;

        if(a%b == 0)
        return a/b;
        else
        return a/b + 1;

    }

    bool isValid(int mid,int n,int h,vector<int> piles)
    {
        
        int count_h = 0;
        for(int i=0;i<n;i++)
        {
            if(piles[i]<= mid)
            count_h++;
            else
            {
                count_h += ceil(piles[i],mid);
            }

            if(count_h > h)
            return false;
        }

        return true;

    }


    int minEatingSpeed(vector<int>& piles, int h) {
        
        int start = 1;
        int end =0;

        int n = piles.size();
        for(int i=0;i<n;i++)
        {
            end = max(piles[i],end);
        }

        int ans =-1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;

            if(isValid(mid,n,h,piles))
            {
                ans = mid;
                end =mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans ;

    }
};
-------------------------------------------
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