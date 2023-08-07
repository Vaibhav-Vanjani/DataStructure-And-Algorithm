//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        
        stack<char> st;
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')   
            {
                st.push('(');
            }
            else if(s[i]==')')
            {
                if(st.top()!='#')
                return true;
                else
                {
                    while(st.top() == '#')
                    st.pop();
                    
                    st.pop();
                }
                
            }
            else
            {
                if((s[i]=='+') or (s[i]=='-') or (s[i]=='*') or (s[i]=='/'))
                {
                    st.push('#');
                }
            }
        }
        return false;
        
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends