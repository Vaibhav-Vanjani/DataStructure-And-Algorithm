//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        int i=0;
        int j=0;
        list<int> l;
        vector<int> ans;
        
        
        while(i<n && j<n)
        {
            if(l.empty())
            l.push_back(arr[j]);
            else
            {
                while(!l.empty() && arr[j]>l.back())
                l.pop_back();
                
                l.push_back(arr[j]);
            }
            
            
            if((j-i+1)<k)
            j++;
            else if((j-i+1)==k)
            {
                ans.push_back(l.front());
                
                if(arr[i] == l.front())
                l.pop_front();
                
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
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
-------------------------------
revisited.
1.
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
     
    //  this test case will tell you why you have to pop from back and not from front
    //  4 1 2
    
    // 4 1 
    // when you will put 2 in list left side of 2 lies a minimum which is of no use
        
        list<int> l;
        vector<int> ans;
        int end =0;
        int start=0;
        
        while(end<n)
        {
            if(l.empty())
            {
                l.push_back(arr[end]);
            }
            else
            {
                int x=l.back();
                while(!l.empty() && x<arr[end])
                {
                    l.pop_back();
                    x=l.back();
                }
                l.push_back(arr[end]);
            }
            
            if((end-start+1)<k)
            {
                end++;
            }
            else if((end-start+1)==k)
            {
                int dummy = l.front();
                ans.push_back(dummy);
                
                if(dummy==arr[start])
                {
                    l.pop_front();
                }
                
                start++;
                end++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends

2.

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int N, int k)
    {
        // your code here
    
        list<int> li;
        vector<int> answer;
        int start=0;
        int end=0;
        int maxi=-1;
        while(start<N && end<N)
        {
          while(li.size()>0 && li.back()<arr[end])
          {
           li.pop_back();
           }
           li.push_back(arr[end]);

            if(end-start+1<k)
            end++;
            else if(end-start+1==k)
            {
                answer.push_back(li.front());
                if(arr[start] == li.front())
                 {
                  li.pop_front();
                  }
                start++;
                end++;
            }
        }
        
        return answer;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends