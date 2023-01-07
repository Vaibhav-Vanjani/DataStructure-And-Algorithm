class Solution {
public:
    

    bool isValid(int mid,vector<int> position,int n,int m)
    {
        int ball = 1;
        int prev=position[0];
        
        
         for(int i=1;i<n;i++)
         {
             if(position[i]-prev>=mid)
             {
                 ball++;
                 prev=position[i];
             }
            
            if(ball==m)
            return true;

         }

             if(ball<m)
             return false;

         return true;


    }
    
    
    
    
    int maxDistance(vector<int>& position, int m) {
        


        // 1 2 3 4 7 

        int start =1;
        sort(position.begin(),position.end());
        int n=position.size();
        int end = position[n-1];
        int res=-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;

            if(isValid(mid,position,n,m))
            {
              res=mid;
              start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
  return res;      

    }
};