
---- 1st Method ----

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
   
    string convertToBinary(int a)
    {
        string binary="";
        int x= 0;
        while(a)
        {
            x = a%2;
            binary = to_string(x) + binary;
            a=a>>1;
        }
        return binary;
    }
    
    
    int countBitsFlip(int a, int b){
        
        // Your logic here
        string first = convertToBinary(a);
        string second = convertToBinary(b);
        int n1 = first.size();
        int n2 = second.size();
        if(n1>n2)
        {
            while(n1>second.size())
            {
                second = '0'+ second ;
            }
        }
        else if(n1<n2)
        {
            while(n2>first.size())
            {
                first='0'+first;
            }
        }
        int n = first.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(first[i]!=second[i])
            count++;
        }
        
        return count;
        
    }
};

----2nd Method ----
using exor approach 

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
   
    
    
    int countBitsFlip(int a, int b){
        
        // Your logic here
	
	

       int answer = a^b;
	// get 1 where there is difference in bit 
       int count=0;
       while(answer)
       {
           if(answer&1) // check if no. is odd
           {
               count++;
           }
           answer=answer>>1; // divide by 2
       }
       return count;
        
    }
};
