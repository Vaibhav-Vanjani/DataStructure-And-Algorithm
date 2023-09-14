//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        int indegree[K]={0};
        for(int i=0;i<N-1;i++)
        {
            string a = dict[i];
            string b = dict[i+1];
            
            int n = a.size();
            int m = b.size();
            
            int sa = 0;
            int sb = 0;
            
            while(sa<n && sb<m)
            {
                if(a[sa]!=b[sb])
                {
                    adj[a[sa]-'a'].push_back(b[sb]-'a');
                    break;
                }
                else
                {
                    sa++;
                    sb++;
                }
            }
        }
        
        for(int i=0;i<K;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
             indegree[adj[i][j]]++;   
            }
        }
        
      queue<int> q;
      for(int i=0;i<K;i++)
      {
          if(!indegree[i])
          q.push(i);
      }
       string ans;
      
      while(!q.empty())
      {
          int size = q.size();
          for(int i=0;i<size;i++)
          {
              int fr = q.front();
              q.pop();
              indegree[fr]=-1;
              ans+='a'+fr;
              
              for(int j=0;j<adj[fr].size();j++)
              {
                  indegree[adj[fr][j]]--;
              }
          }
          
          for(int k=0;k<K;k++)
          {
              if(indegree[k]==0)
              q.push(k);
          }
      }
      
     
      for(int i=0;i<K;i++)
      {
          if(indegree[i]!=-1)
          ans+=('a'+i);
      }
      return ans;
    
    }
};


//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends