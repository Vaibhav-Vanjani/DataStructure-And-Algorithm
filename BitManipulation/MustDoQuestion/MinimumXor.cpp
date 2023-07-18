class Solution {
public:

    int getBitsOfNum(int a)
    {
        int cnt=0;
        while(a)
        {
            if(a&1)
            cnt++;

            a>>=1;
        }
        return cnt;
    }

    string numberToString(int num1)
    {
        string str="";
        while(num1)
        {
            if(num1&1)
            str='1'+str;
            else
            str='0'+str;

            num1>>=1;
        }
        return str;
    }

    int minimizeXor(int num1, int num2) {
        
        int BitsOfNumTwo = getBitsOfNum(num2);
        int BitsOfNumOne = getBitsOfNum(num1);
        // int ans=0;

        // edge case
        // if BitsOfNumTwo gets zero before num1 and vice cersa

    //  0000000000000001?


       string str = numberToString(num1);
       long long ans=0;
        int size =str.size(); 

        if(BitsOfNumOne == BitsOfNumTwo)return num1;


        if(BitsOfNumOne >BitsOfNumTwo)
        {
          for(int i=0;i<str.size();i++)
          {
              if(str[i]=='1')
              {
                  ans+=1<<(str.size()-1-i); 
                  BitsOfNumTwo--;   
              }
              if(!BitsOfNumTwo)return ans;
          }
        }
        else
        {
          BitsOfNumTwo-=BitsOfNumOne;
          reverse(str.begin(),str.end());
             for(int i=0;i<str.size();i++)
          {
              if(str[i]=='0')
              {
                  num1+=1<<(i); 
                  BitsOfNumTwo--;   
              }
              if(!BitsOfNumTwo)return num1;
          }
        
        int size=str.size();
          while(BitsOfNumTwo)
          {
              num1+=1<<(size);
              size++;
              BitsOfNumTwo--;   
              if(!BitsOfNumTwo)return num1;
          }

        }

    return ans;

      }
};