//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
	public:
	
	
    // 	Euclids algorithm to find GCD(HCF)
    // gcd(a,b) == gcd(a-b,b)
	
	int recursive_gcd(int a ,int b)
	{
	    if(a==0)return b;
	    if(b==0)return a;
	    
	    if(a>b)
	    return recursive_gcd(a-b,b);
	    else
	    return recursive_gcd(a,b-a);
	    
	}
	
	
    int gcd(int A, int B) 
	{ 
	    // code here
	    
	    return recursive_gcd(A,B);
	      
	} 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends