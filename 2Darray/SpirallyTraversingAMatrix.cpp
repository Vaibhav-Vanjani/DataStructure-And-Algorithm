//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    
    // 1 2
    // 4 3
    
    
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int tempR= r;
        int tempC = c;
        
        vector<int> ans;
     int rs=0;
     int re=r-1;
     int cs=0;
     int ce=c-1;
     int i,j;
     
     if(r==1 or c==1)
     {
         if(r==1 && c==1)
         {
             ans.push_back(matrix[0][0]);
             return ans;
         }
         else if(r==1 and c!=1)
         {
             while(cs<=ce)
             {
                 ans.push_back(matrix[0][cs]);
                 cs++;
             }
             return ans;
         }
         else if(r!=1 and c==1)
         {
             while(rs<=re)
             {
                 ans.push_back(matrix[rs][0]);
                 rs++;
             }
             return ans;
         }
     }
     
        
        while(rs<=re && cs<=ce)
        {
            j=cs;
            while(j<=ce)
            {
                ans.push_back(matrix[rs][j]);
                j++;
            }
           
           rs++; 
           i=rs;
           
            while(i<=re)
            {
                ans.push_back(matrix[i][ce]);
                i++;
            }
            
            ce--;
            j=ce;
            
            if(rs>re or cs>ce)
            return ans;
            
            while(j>=cs)
            {
                ans.push_back(matrix[re][j]);
                j--;
            }
            
            re--;
            i=re;
            
            
            if(rs>re or cs>ce)
            return ans;
            
            while(i>=rs)
            {
                ans.push_back(matrix[i][cs]);
                i--;
            }
            
            cs++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends