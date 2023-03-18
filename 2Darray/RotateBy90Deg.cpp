//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


// } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{

    
    //method1

    int n=matrix.size();
    int m=matrix[0].size();
    
    vector<int> temp(m,0);
    int ans[n][m];
    memset(ans,-1,sizeof(ans));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans[i][j]=matrix[j][m-i-1];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            matrix[i][j]=ans[i][j];
        }
    }
    
    
   
    
}


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}


// } Driver Code Ends





------------------method2

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


// } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int n=matrix.size();
    int m=matrix[0].size();
    int start;
    int end;
    int mid;
    int temp;
    
    
    //reverse
    for(int i=0;i<n;i++)
    {
        start = 0;
        end = m-1;
        mid = start + (end-start)/2;
        while(start<=mid)
        {
            swap(matrix[i][start],matrix[i][end-start]);
            start++;
        }
    }

    
    //transpose
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<m;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    
    
    
    
   
    
}


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}


// } Driver Code Ends