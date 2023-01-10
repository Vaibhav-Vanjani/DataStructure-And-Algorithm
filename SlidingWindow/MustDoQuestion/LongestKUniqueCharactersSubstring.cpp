//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    
    int start =0;
    int end =0;
    unordered_map<char,int> mp;
    int count = 0;
    int N=s.size();
    int maximumLength = -1;
    
    int number=1;
    
    while(end<N)
    {
        mp[s[end]]++;
        if(mp[s[end]]==1)
        count++;
        
        if(count<k)
        end++;
        else if(count==k)
        {
            maximumLength = max(maximumLength,end-start+1);
            end++;
        }
        else if(count>k)
        {
            while(count>k)
            {
                mp[s[start]]--;
                
                if(mp[s[start]]==0)
                count--;
                
                start++;
            }
            end++;
        }
        
       
        
        
    }
    return maximumLength;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends