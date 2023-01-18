class Solution {
public:
    int bitwiseComplement(int n) {
        
        if(n==0)
        return 1; //important edge case.

        int i=0,sum=0;
        while(n)
        {
            if(!(n&1))
            {
                sum+=1<<i;
            }
            i++;
            n>>=1;
        }
        return sum;
    }
};