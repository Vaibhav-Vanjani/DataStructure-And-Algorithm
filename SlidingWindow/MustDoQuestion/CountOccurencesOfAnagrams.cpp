//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int size=pat.size();
	    unordered_map<char,int> mp;
	    
	    for(int i=0;i<size;i++)
	    {
	        mp[pat[i]]++;
	    }
	    
	    int count = mp.size();
	    int i=0;
	    int j=0;
	    int n =txt.size();
	    int ans =0;
	    
	    while(i<n && j<n)
	    {
	       if( mp.find(txt[j])!=mp.end() ) 
	       {
	           mp[txt[j]]--;
	           
	           if(mp[txt[j]]==0)
	           count--;
	       }
	       
	       if((j-i+1)<size)
	       j++;
	       else if((j-i+1)==size)
	       {
	            if(count==0)
	            ans++;
	            
	            if(mp.find(txt[i])!=mp.end())
	            {
	                mp[txt[i]]++;
	                if(mp[txt[i]]==1)
	                count++;
	            }
	            
	            i++;
	            j++;
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
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
------------------------------------------
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	int N=txt.size();
	int k = pat.size();
	int start=0;
	int end=0;
	unordered_map<char,int> wordMap;
	
	for(int i=0;i<k;i++)
	{
	    wordMap[pat[i]]++;
	}
	
	int count = wordMap.size();
	int anagram=0;
	while(start<N && end<N)
	{
	    if(wordMap.find(txt[end])!=wordMap.end())
	    {
	        wordMap[txt[end]]--;
	        if(wordMap[txt[end]]==0)
	        {
	            count--;
	        }
	    }
	    
	    if(end-start+1<k)
	    {
	        end++;
	    }
	    else if(end-start+1==k)
	    {
	        if(count==0)
	        anagram++;
	        
	        if(wordMap.find(txt[start])!=wordMap.end())
	        {
	            wordMap[txt[start]]++;
	            if(wordMap[txt[start]]==1)
	            count++;
	        }
	        
	        start++;
	        end++;
	    }
	    
	}
	

	 return anagram;
	 
	 
	
	
	    
	    
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends