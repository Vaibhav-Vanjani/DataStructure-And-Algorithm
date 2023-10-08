//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        // Write Your Code here
        // 1 2 3 4
        sort(candies,candies+N);
        int sum=0;
        vector<int> ans;
        int n = N;
        for(int i=0;i<n;i++)
        {
            sum+=candies[i];
            n=n-k;
        }
        ans.push_back(sum);
        sum=0;
        int zero =0;
        
        // 4 3 2 1  
        for(int i=N-1;i>=zero;i--)
        {
            sum+=candies[i];
            zero+=k;
        }
        
        ans.push_back(sum);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends