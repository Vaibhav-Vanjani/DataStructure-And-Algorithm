//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N)
    {
        // code here 
        int start=0;
        int end=0;
       long sum=0,maxi=INT_MIN;
        while(start<N && end<N)
        {
            sum+=Arr[end];
            
            if(end-start+1<K)
            end++;
            else if(end-start+1==K)
            {
                maxi=max(sum,maxi);
                sum-=Arr[start];
                start++;
                end++;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends