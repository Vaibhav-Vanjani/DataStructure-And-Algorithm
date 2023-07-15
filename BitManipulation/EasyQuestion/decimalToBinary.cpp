//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

void toBinary(int N)
{
    // your code here
    
    string str="";
    while(N)
    {
        if(N&1)
        str+='1';
        else
        str+='0';
        
        N>>=1;
    }
    reverse(str.begin(),str.end());
    cout<<str;
        
}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    toBinary(n);
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends