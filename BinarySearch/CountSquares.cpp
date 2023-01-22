//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // code here

	use long long as mid*mid can give integer overflow
       long long start =1;
       long long end = N;
       long long count=0;
       
       while(start<=end)
       {
           long long mid=start + (end-start)/2;
           
           if(mid*mid < N)
           {
            count=mid;
            start=mid+1;
           }
           else
           end=mid-1;
       }
       return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends