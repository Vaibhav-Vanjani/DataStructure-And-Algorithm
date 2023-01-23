//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int find(int x)
    {
        // to find xor of any number from 1 to x 
        // use this
        if(x%4 == 0)
        return x;
        
        else if(x %4 == 1)
        return 1;
        
        else if(x%4 ==2)
        return x+1;
        
        else 
        return 0;
        
        /*
        //XOR for (1 to 9) 
        //This pattern follows for all numbers
        1 -> 1
        2 -> n+1 -> 3
        3 -> 0
        4 -> n -> 4
        5 -> 1
        6 -> n+1 -> 7
        7 -> 0
        8 -> n -> 8
        9 -> 1
        
        */
    }
    int findXOR(int l, int r) {
        // complete the function here
         //done using a formula 
        // XOR(r) ^ XOR(l-1)
        
        return find(r)^find(l-1);
        //because if l is 6 ane r is 3
        //XOR of numbers between the range 3 to 6 is 
        // 3 ^ 4 ^ 5 ^ 6
        //which is same as 
        // 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6    ^     1 ^ 2
        //XOR(r) ^ XOR(l-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends