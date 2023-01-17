//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int findUnique(int a[], int n, int k) {
        
        int count[32]={0}; //all indexes have been assigned as zero
        
        for(int i=0;i<=31;i++)//as largest bit could be 2^31
        {
            int num=1<<i; //mask
            for(int j=0;j<n;j++)
            {
                if(a[j] & num)//masking 
                count[i]++; //increment it only when masked no. exist
            }
        }
        
        
        int sum=0;
        //no. which exits k time there count[i] will be divisible by k
        // rest would give the number which appeared only one time
        for(int i=0;i<=31;i++)
        {
            sum+=(count[i]%k)*(1<<i);
        }
        return sum;
        
        
       
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        cout << obj.findUnique(a, n, k) << endl;
    }
}
// } Driver Code Ends