//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_map<string,int> mp;
        unordered_map<string,int> vis;
        
        int wordListSize = wordList.size();
        for(int i=0;i<wordList.size();i++)
        {
            mp[wordList[i]]++;
        }
        string str = startWord;
        int ans=INT_MAX;
        vis[startWord]=1;
        
        queue<pair<string,int>> q;
        q.push({str,1});
        
        while(!q.empty())
        {
            string str = q.front().first;
            int cnt = q.front().second;
            q.pop();
            
             if(str == targetWord)
             return cnt;
            
             for(int i=0;i<str.size();i++)
             {
                char d = str[i];
                 for(char j = 'a'; j<='z';j++)
                 {
                     str[i]=j;
                      if(!vis[str] && mp[str])
                      {
                          vis[str]=1;
                          q.push({str,cnt+1});
                      }
                 }      
             str[i]=d;
             }
        }
      
      return 0;
      
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends