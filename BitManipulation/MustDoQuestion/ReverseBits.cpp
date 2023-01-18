class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string temp="";

        while(n)
        {
            temp+=to_string(n&1);
            n>>=1;
        }

        // This step is important 
        // as 5 = 000000000000000000000000000000000101
        // so its reverse bits are 
        // 1010000000000000000000000000000000000000000
        while(temp.size()<32)
        {
            temp+=to_string(0);
        }


        
        int sum=0;
        int length= temp.size();
        int count=0;
      

        

        for(int i=length-1;i>=0;i--)
        {
            if(temp[i]=='1')
            {
                sum+=(1<<count);
            }
            count++;
            
        }
        return sum;

    }
};