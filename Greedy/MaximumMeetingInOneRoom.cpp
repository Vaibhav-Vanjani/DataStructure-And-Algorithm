//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    bool static comp(pair<int,pair<int,int>>a,pair<int,pair<int,int>> b)
    {
        return a.first<b.first;
    }
public:
    vector<int> maxMeetings(int n,vector<int> &S,vector<int> &F){
          vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({F[i],{S[i],i+1}});
        }
        sort(v.begin(),v.end(),comp);
        
        // int cnt=0;
        vector<int> ans;
        int endTime = -1;
        int size = v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i].second.first>endTime)
            {
                // cnt++;
                endTime = v[i].first;
                ans.push_back(v[i].second.second);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends