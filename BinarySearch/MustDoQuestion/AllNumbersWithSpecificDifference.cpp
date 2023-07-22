//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long getMidCount(long long mid)
    {
        long long ans = 0;
        
        while(mid)
        {
            ans += mid%10;
            mid=mid/10;
        }
        return ans;
    }
  
    long long getCount(long long N , long long D) {
        // code here
        
        // 1-9 == 0
        // 10-19 == 9
        // 20-29 == 18
        
        
        long long start = 1 ;
        long long end = N;
        
        long long mid = 0;
        long long int ans = 0;
        while(start<=end)
        {
             mid = start +(end-start)/2;
             
             if( (mid - getMidCount(mid)) >= D )
             {
                 ans += end-mid+1;
                 end=mid-1;
             }
             else
             {
             start=mid+1;
             }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N,D;

        cin>>N>>D;

        Solution ob;
        cout << ob.getCount(N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends

revisited.
1.
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  long long getSum(long long mid)
  {
      long long ans=0;
      while(mid)
      {
          ans+=mid%10;
          mid/=10;
      }
      return ans;
  }
  
  
    long long getCount(long long N , long long D) {
        // code here
        
        // 0 to 9 == 0
        // 10 to 19 == 9
        // 20 to 29 == 18
        
        long long start=0;
        long long end = N;
        long long ans=0;
        
        while(start<=end)
        {
            long long mid =start+ (end-start)/2;
            
            if( (mid-getSum(mid)) >= D)
            {
                ans+=end-mid+1;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N,D;

        cin>>N>>D;

        Solution ob;
        cout << ob.getCount(N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends

2.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  long long getSum(long long mid)
  {
      long long ans=0;
      while(mid)
      {
          ans+=mid%10;
          mid=mid/10;
      }
      return ans;
  }
  
  
  bool isValid(long long mid,long long D)
  {
      long long sum = getSum(mid);
      long long diff = mid-sum;
      
      if(diff>=D)
      return true;
      else
      return false;
  }
  
  
    long long getCount(long long N , long long D) {
        // code here
        // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
        // 0 0 0 0 0 00  0 0  9  9  9  9  9  9  9  9 
        
        if(N>=1 && N<=9 && D!=0)
        return 0;
        
        
        
        
        
        long long start =0;
        long long end = N;
        long long ans=0;
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            if(isValid(mid,D))
            {
                ans+=end-mid+1;
                end=mid-1;
            }
            else
            start=mid+1;
        }
       
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N,D;

        cin>>N>>D;

        Solution ob;
        cout << ob.getCount(N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends