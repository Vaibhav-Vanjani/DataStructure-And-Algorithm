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