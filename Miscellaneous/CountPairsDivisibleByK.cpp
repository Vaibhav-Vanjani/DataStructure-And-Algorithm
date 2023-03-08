//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int k)
    {
        //code here
        
        // 2 2 1 7 5 3 
        // 4 
        
        // (x + y)%k == 0
        
        // x%k + y%k == 0
        
        // x%4 + y%4 == 4
        
        
        // it will not make a difference here for adding %4 here 
        // x%4 = (4 - y%4)%4
        
        
        // to handle this type of case x%k is used
        // 6%2  == (2 - 10%2)%2
        
        unordered_map<int,int> mp;
        long long count=0;
        for(int i=0;i<n;i++)
        {
            int x=k-(A[i]%k);
            int y=A[i]%k;
           
            count+=mp[x%k];
            mp[y]++;
        
        }
        return count;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends