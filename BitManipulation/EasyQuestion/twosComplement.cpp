//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
class Solution{
public:
    int twosComplement(int N){
        //code here
        
        if(!N)return 1;
    
        int len=0;
        int sum=0;
        while(sN)
        {
           if(!(N&1))
           {
               sum+=1<<len;
           }
          len++;
          N=N>>1;
        }
        return sum+1;
    
    }
        
        
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        Solution ob;
        cout<<ob.onesComplement(n)<<"\n";
    }
}
// } Driver Code Ends