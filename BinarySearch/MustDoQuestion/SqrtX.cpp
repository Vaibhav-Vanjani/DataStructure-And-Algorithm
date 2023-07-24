class Solution {
public:

 // 5 

//  3  


 //if given you can't use long long a simple deduction has to be made 
 // mid*mid can give a long long ans 
 // here mid*mid <= x can also be wriiten as (mid <= x/mid)   

    bool isValid(int mid,int x)
    {
       return mid<= x/mid;
    }


  

    int mySqrt(int x) {
        
        int start = 1;
        int end = x;
    

        int ans = 0;
        while(start<=end)
        {
            int mid = start + (end-start)/2;

            if(isValid(mid,x))
            {
                ans = mid;
                start=mid+1;
            }
            else
            end = mid-1;
        }
        return ans;
    }
};