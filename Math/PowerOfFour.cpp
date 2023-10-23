class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n==0)return false; 

        double a = log(n);
        double b = log(4);
         return a/b == ceil(a/b);
        
    }
};