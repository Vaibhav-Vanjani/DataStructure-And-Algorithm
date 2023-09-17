//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {
        // code here
         unordered_map<string,int> mp;
        unordered_map<string,int> vis;
        
        int wordListSize = wordList.size();
        for(int i=0;i<wordList.size();i++)
        {
            mp[wordList[i]]++;
        }
        string str = startWord;
        vis[startWord]=1;
        
        queue<vector<string>> q;
        vector<string> store;
        store.push_back(str);
        q.push(store);
        int lvl = INT_MAX;
        
        vector<vector<string>> ans;
        
        while(!q.empty())
        {
            vector<string> temp = q.front();
            str = temp.back();
            q.pop();
            vis[str]=1;
            
             if(str == targetWord)
            {
                if(lvl >= temp.size()){
                    lvl = temp.size();
                    ans.push_back(temp);
                }
            }
            
             for(int i=0;i<str.size();i++)
             {
                char d = str[i];
                 for(char j = 'a'; j<='z';j++)
                 {
                     str[i]=j;
                      if(!vis[str] && mp[str])
                      {
                          temp.push_back(str);
                          q.push(temp);
                          temp.pop_back();
                      }
                 }      
                str[i]=d;
             }
        }
      
      return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends