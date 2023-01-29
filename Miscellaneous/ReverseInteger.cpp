class Solution {
public:
    int reverse(int x) {
        
        long long ans=0;
       long long tens= 1;
       int temp=x;

        int neg=1;
        if(temp<0)
        neg=-1;

        // for length get tens place
       while(temp)
       {
           temp/=10;
           if(!temp)break;
           tens*=10;
       }

        //
       while(x)
       {
           ans+= (x%10)*tens ;
           x/=10;
           tens/=10;
       }
      
       if(ans<= (pow(2,31)-1) && ans>=(-1*pow(2,31)))return ans;
       else return 0;


    }
};