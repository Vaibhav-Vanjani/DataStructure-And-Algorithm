class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        approach1:
        if(!n)return false;

        if(ceil(log2(n)) == log2(n))
        return true;

        return false;

        approach2:
         if(n==0) return false;
        while(n%2==0) n/=2;
        return n==1;

        approach 3:
         if(n<=0) return false;
        return ((n&(n-1))==0);
    }
};