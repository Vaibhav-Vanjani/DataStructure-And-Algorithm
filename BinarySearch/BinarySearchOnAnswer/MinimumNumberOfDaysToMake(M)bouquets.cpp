revisited.
1.
class Solution {
public:


    bool isAnswer(int mid,int m,int k,vector<int> bloomday)
    {
        int count=0;
        int bouquet=0;
        for(int i=0;i<bloomday.size();i++)
        {

            if(mid>=bloomday[i])
            {
                count++;
                if(count==k)
                {
                    bouquet++;
                    count=0;

                    if(bouquet==m)
                    return true;
                }
            }
            else
            {
                count=0;

            }
        }
        return false;
    }


    int minDays(vector<int>& bloomday, int m, int k) {
        // make m bouquet
        // use k adjacent flower
        //bloomday[i]= a flower bloom at that day can be used in exactly 1 bouquet


    int start = INT_MAX;
    int end = INT_MIN;

         for(int i=0;i<bloomday.size();i++)
         {
             start=min(start,bloomday[i]);
             end=max(end,bloomday[i]);
         }

        int res=-1;
         while(start<=end)
         {
             int mid = start + (end-start)/2 ;
             if(isAnswer(mid,m,k,bloomday))
             {
                 res = mid;
                 end=mid-1;
             }
             else
             {
                 start=mid+1;
             }
         }
         return res;
    }
};


2.

class Solution {
public:

    bool isValid(vector<int> bloomDay,int m,int k,int n,int mid)
    {
      
       int bouquet=0;
       int adjacent=0;
       for(int i=0;i<n;i++)
       {

           if(adjacent==k)
           {
               bouquet++;
               adjacent=0;
           }

           if(bloomDay[i]<=mid)
            adjacent++;
           else
            adjacent=0;

           if(bouquet==m)
           return true;

       }

        if(adjacent==k)
           {
               bouquet++;
               adjacent=0;
           }

       if(bouquet>=m)
       return true;

       return false;


    }




    int minDays(vector<int>& bloomDay, int m, int k) {
        
        
        
        
        int n=bloomDay.size();
        int start=1;
       
        
        
        
        
        int maxi=-1;
        for(int i=0;i<n;i++)
        {
            maxi=max(bloomDay[i],maxi);
        }

        int end=maxi;
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(isValid(bloomDay,m,k,n,mid))
            {
                res=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }

        return res;



    }
};