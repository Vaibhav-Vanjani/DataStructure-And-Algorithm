class Solution {
public:
    int kthGrammar(int n, int k) {
        
       if(k==1)return 0;
       if(n==2 && k==2)return 1;

         
       if(k%2!=0)
       {
           return kthGrammar(n-1,k/2+1);
       }
       else
       {
           return kthGrammar(n-1,k/2)==0 ? 1 : 0 ;
       }

    }
};