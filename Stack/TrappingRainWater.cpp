//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    
     vector<int> getMaxFromLeft(int arr[], int n)
    {
        stack<int> st;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            ans.push_back(-1);
            else
            {
                if(arr[i]>=st.top())
                {
                    while(!st.empty() && arr[i]>=st.top())
                    st.pop();
                    
                    if(st.empty())
                    ans.push_back(-1);
                    else
                    ans.push_back(st.top());
                    
                }
                else
                ans.push_back(st.top());
            }
            st.push(arr[i]);
        }
        return ans;
    }
    
    vector<int> getMaxFromRight(int arr[], int n)
    {
        stack<int> st;
        vector<int> ans;
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            ans.push_back(-1);
            else
            {
                if(arr[i]>=st.top())
                {
                    while(!st.empty() && arr[i]>=st.top())
                    st.pop();
                    
                    if(st.empty())
                    ans.push_back(-1);
                    else
                    ans.push_back(st.top());
                    
                }
                else
                ans.push_back(st.top());
            }
            st.push(arr[i]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    long long trappingWater(int arr[], int n){
        // code here
        
        int lMax=0;
        int rMax=0;
        
        vector<int> l ;
      for(int i=0;i<n;i++)
      {
        lMax = max(arr[i],lMax);
        l.push_back(lMax);
      }
      
      
        vector<int> r ;
      for(int i=n-1;i>=0;i--)
      {
        rMax = max(arr[i],rMax);
        r.push_back(rMax);
      }
      
      reverse(r.begin(),r.end());
      
      int size1 = l.size();
      int size2 = r.size();
      
      
      long long ans=0;
      for(int i=0;i<n;i++)
      {
          
          int temp = min(l[i],r[i]);
          ans+=(temp-arr[i]);
      }
      return ans;
      
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends