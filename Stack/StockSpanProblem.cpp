//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stock’s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       int count=1;
    //   int size = temp.size();
       vector<int> ans;
       stack<pair<int,int>> st;
       
       
       
       for(int i=0;i<n;i++)
       {
           if(st.empty())
           ans.push_back(i+1);
           else
           {
              if(price[i]>=st.top().first)
              {
                  while(!st.empty() && price[i]>=st.top().first)
                  {
                      st.pop();
                  }
                  
                  if(st.empty())
                  ans.push_back(i+1);
                  else
                  ans.push_back(i-st.top().second);
              }
              else
              ans.push_back(i-st.top().second);
           }
           st.push({price[i],i});
       }
       
    //   int size=ans.size();
    //   for(int i=0;i<size;i++)
    //   {
    //       ans[i] = i-ans[i];
    //   }
       
       return ans;
    }
};




//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends