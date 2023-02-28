revisited.
1.
//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    // imp.
    // (student < = no. of book) condition is true
    
    bool isAnswer(int mid,int A[],int N,int M)
    {
        int student=1;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            if(A[i]>mid)return false;
            
            sum+=A[i];
            if(sum>mid)
            {
                sum=A[i];
                student++;
                
                if(student>M)return false;
            }
        }
        
       return true;
    }
    
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        // m=no. of student 
        // n=no. of books
        // A[i]= ith book has pages A[i]
        
        if(M>N)return -1;
        
        
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
        }
        int start=0;
        int end=sum;
        
        int res=-1;
        while(start<=end)
        {
            int mid=start+ (end-start)/2;
            
            if(isAnswer(mid,A,N,M))
            {
                res=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return res;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends



2.

//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isValid(int A[],int n,int M, int mx)
    {
        int student=1;
        int sum=0;
       for(int i=0;i<n;i++)
        {
            sum+=A[i];
            if(sum>mx)
            {
                student++;
                sum=A[i];
            }
            
            if(A[i]>mx or student>M)
            return false;
            
            
            // if(A[i]>mx) is not written here this test case fails     
            //11
            //13 31 37 45 46 54 55 63 73 84 85
            // 9
            
            //my ans =81
            //expexted ans =85
            //13 31 37      45 46 54 55 63 73 84 85
             //   81        45 46 54 55 63 73 84 85 from this
             // 85 is max
             //mx=81 but thats true as 85 is greater than 81
             // so this can't be valid ans.
        
        }
        return true;
    }
    
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        if(N<M)
        {
            return -1;
        }
        
        int start=0;
        int sum=0;
        for(int i=0;i<N;i++)
        {sum+=A[i];}
        
        
        int end=sum;
        int res=-1;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
        
            if(isValid(A,N,M,mid))
            {
                res=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends