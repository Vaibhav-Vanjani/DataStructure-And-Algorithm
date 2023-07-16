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


approach2:
class Solution {
public:

  
  string get_string(uint32_t a)
  {
      string ans ="";
      while(a)
      {
          if(a&1)
          ans+='1';
          else
          ans+='0';

        a>>=1;
      }
      reverse(ans.begin(),ans.end());
      return ans;
  }


    uint32_t reverseBits(uint32_t n) {
        

        // uint32_t meh actually number de rakha hoga 
        // return n;
        uint32_t sum=0;
        string ans = get_string(n);

        // edge case is if it is not 32 bit size string 
        while(ans.size()<32)
        {
          ans='0'+ans;
        }

        for(int i=0;i<ans.size();i++)
        {
            if(ans[i] == '1')
            sum+=1<<i;

        }
        return sum;
    }
};