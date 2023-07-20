//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    // static int temp=0;
public:
    
    int count_highest_power_less_than_N(int n)
    {
        int i=0;
        while((1<<i) <= n)
       {
           i++;
       }
    
        return i-1;
    }
    
    int countBits(int n){
    //     // code here
    //     int cnt[32]={};
    //     for(int i=0;i<=31;i++)
    //     {
    //         int mask = 1<<i;
            
    //         for(int j=1;j<=n;j++)
    //         {
    //             if((mask)&j)
    //             cnt[i]++;
    //         }
    //     }
    //     // return cnt[1];
        
    // //   001   1
    // //   010   1  2
    // //   011   2  4  
    // //   100   1  5
    // //   101   2  7
    // //   110   2  9   
    // //   111   3  12
    // //  1000   1  13  
    // // 
        
        
        
        
        
    //     long long ans=0;
    //     for(int i=0;i<=31;i++)
    //     {
    //         ans+=cnt[i];
    //     }
        
    //     return ans;
    
//     Numbers till n, are:
// 0  -> 0000000
// 1  -> 0000001
// 2  -> 0000010
// 3  -> 0000011
// 4  -> 0000100
// 5  -> 0000101
// 6  -> 0000110
// 7  -> 0000111
// 8  -> 0001000
// 9  -> 0001001
// 10 -> 0001010
// 11 -> 0001011
// Now we can see that, from 0 to pow(2,1)-1 = 1, we can pair elements top-most with bottom-most, 
// and count of set bit in a pair is 1
// Similarly for pow(2,2)-1 = 4, pairs are:
// 00 and 11
// 01 and 10
// here count of set bit in a pair is 2, so in both pairs is 4
// Similarly we can see for 7, 15, ans soon.....
// so we can generalise that, 
// count(x) = (x*pow(2,(x-1))), 
// here x is position of set bit of the largest power of 2 till n
// for n = 8, x = 3
// for n = 4, x = 2
// for n = 5, x = 2
// so now for n = 11,
// we have added set bits count from 0 to 7 using count(x) = (x*pow(2,(x-1)))
// for rest numbers 8 to 11, all will have a set bit at 3rd index, so we can add 
// count of rest numbers to our ans, 
// which can be calculated using 11 - 8 + 1 = (n-pow(2,x) + 1)
// Now if notice that, after removing front bits from rest numbers, we get again number from 0 to some m
// so we can recursively call our same function for next set of numbers, 
// by calling countSetBits(n - pow(2,x))
// 8  -> 1000  -> 000 -> 0
// 9  -> 1001  -> 001 -> 1
// 10 -> 1010  -> 010 -> 2
// 11 -> 1011  -> 011 -> 3
    
    
    // for 11
// 0  -> 0000000
// 1  -> 0000001
// 2  -> 0000010
// 3  -> 0000011
// 4  -> 0000100
// 5  -> 0000101
// 6  -> 0000110
// 7  -> 0000111  formula is 2^x-1 * x where x is highest power less than n

// 8  -> 0001000      8  -> 0001   000  
// 9  -> 0001001     9  -> 0001    001
// 10 -> 0001010   10 -> 0001      010
// 11 -> 0001011   11 -> 0001      011
                    //   = n-2^x+1    recursive
          if(n<2)return n;   
                    
           int cnt = count_highest_power_less_than_N(n);
           
           return (cnt)*(1<<(cnt-1)) + (n-(1<<cnt)+1) + countBits(n-(1<<cnt));
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends