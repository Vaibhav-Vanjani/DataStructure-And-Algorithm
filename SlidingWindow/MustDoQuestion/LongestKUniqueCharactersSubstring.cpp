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
        
        int i=0;
        int j=0;
        int n = s.size();
        list<char> l;
        int count =0;
        int maxi=0;
        unordered_map<char,int> mp;
        
        if(k>n)return -1;
        
        while(i<n && j<n)
        {
            mp[s[j]]++;
            if(mp[s[j]]==1)
            {
                count++;
            }
            l.push_back(s[j]);
            
            if(count<k)
            j++;
            else if(count==k)
            {
                int size = l.size();
                maxi = max(maxi,size);
                j++;
            }
            else
            {
                while(!l.empty() && count>k)
                {
                    mp[l.front()]--;
                    
                    if(mp[l.front()]==0)
                    count--;
                    
                    i++;
                    l.pop_front();
                }
                //  int size = l.size();
                // maxi = max(maxi,size);
                j++;
            }
            
        }
        return maxi;
        
        
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
----------------------

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