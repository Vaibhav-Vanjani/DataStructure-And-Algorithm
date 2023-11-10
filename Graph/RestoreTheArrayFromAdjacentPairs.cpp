class Solution {
public:

  void dfs(unordered_map<int,vector<int>> &ans, int k,vector<int> &o,unordered_map<int,int> &vis )
    {
        vis[k]=1;
       for(int i=0;i<ans[k].size();i++)
       {
           if(!vis[ans[k][i]])
          {     vis[ans[k][i]]=1;
                o.push_back(ans[k][i]);
               dfs(ans,ans[k][i],o,vis);
          }
       }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        int n =  adjacentPairs.size();   
        unordered_map<int,vector<int>> ans;
        unordered_map<string,int> mp;
         unordered_map<int,int> cnt;
        string key = "";
        
        for(int i=0;i<n;i++)
        {
            int a = adjacentPairs[i][0];
            int b = adjacentPairs[i][1];
            if(a<b)
            key = to_string(a) + '_' +  to_string(b);  
            else
            key = to_string(b) + '_' +  to_string(a);

           if(!mp.count(key))
           {
            cnt[adjacentPairs[i][0]]++;
            cnt[adjacentPairs[i][1]]++;
            
            ans[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            ans[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
            }   
        }

        unordered_map<int,int> vis;
        vector<int> o;
        for(auto it:cnt)
        {
            if(it.second==1)
            {
                if(!vis[it.first])  
                {      o.push_back(it.first);
                    vis[it.first]=1;
                    dfs(ans,it.first,o,vis);
                }  
            }
        }  
        return o;

        
            }
};