class Solution {
public:
    int divide(int dividend, int divisor) {
        
        

//   watch techadora video for this question if any doubt
      
    //   sum   3  6  12 24  48 96 192
    //   count 1   2  4  8  16 32 64

//  if the quotient is strictly greater than 231 - 1, 
// then return 231 - 1, and if the quotient is strictly less 
// than -231, then return -231.

    if(dividend==INT_MIN && divisor==-1)return INT_MAX;
    if(dividend==INT_MIN && divisor==1)return INT_MIN;
    
    int sign =1;
    if((dividend>0 && divisor<0) or (dividend<0 && divisor>0))sign = 0;

    long int dvd = abs(dividend);
    long int dvs = abs(divisor);
    long int res=0;
     while(dvd >= dvs) 
     {
          long int sum = dvs; long int count = 1;
           while(dvd>=sum)
           {
               sum<<=1; //6
               count<<=1; // 2
           }
          
          count>>=1;
          sum>>=1;

          res+=count;
          dvd-=sum;
     }            

     if(sign)return res;
     else return -res;

    }
};