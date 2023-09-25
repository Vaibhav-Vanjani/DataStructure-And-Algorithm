//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class DisjointSet {
public: 
vector<int> rank,parent,size;

DisjointSet(int n) {
parent.resize(n+1);
size.resize(n+1,1);
rank.resize(n+1,0);
for(int i=0;i<=n;i++) parent[i] = i;
}  
 
int findUPar(int node) {
if(node == parent[node]) return node;
return parent[node] = findUPar(parent[node]);
}
  void unionByRank(int u,int v){
     int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
      
  }
void unionBySize(int u,int v) {
int fu = findUPar(u);
int fv = findUPar(v);
 
if(fu == fv) return ;
if(size[fu] < size[fv]) parent[fu] = fv,size[fv]+=size[fu];
else parent[fv] = fu,size[fu]+=size[fv];
}

   
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n=accounts.size();
       
        map<string,int>mp;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    ds.unionByRank(mp[accounts[i][j]],i);
                }
                else{
                    mp[accounts[i][j]]=i;
                }
            }
            
        }
        map<int,vector<string>> temp;
        
        for(auto it:mp){
            int i=ds.findUPar(it.second);
            temp[i].push_back(it.first);
        }
          vector<vector<string>> ans;
          
          for(auto it:temp){
              vector<string>str;
              str=it.second;
              str.insert(str.begin(),accounts[it.first][0]);
              ans.push_back(str);
              
          }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends