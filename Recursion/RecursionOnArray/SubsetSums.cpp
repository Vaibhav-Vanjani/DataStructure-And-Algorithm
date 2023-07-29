//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void helper(vector<int> arr,int N,int sum,int i,vector<int> &output)
    {
        if(i==N)
        {
            output.push_back(sum);
            return ;
        }
        
        helper(arr,N,sum,i+1,output);
        helper(arr,N,sum+arr[i],i+1,output);
    }



    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int sum=0;
        int i=0;
        vector<int> output;
        helper(arr,N,sum,i,output);
        return output;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends