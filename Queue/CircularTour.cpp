//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
 
    bool helper(int curr,int i,int n,int arr[])
    {
        
        queue<int> q;
        for(int j=i+1;j<n;j++)
        {
            q.push(arr[j]);
        }
        
        for(int j=0;j<=i-1;j++)
        {
            q.push(arr[j]);
        }
        
        int sum=curr;
        while(!q.empty())
        {
            if(sum<0)
            return false;
            
            sum+=q.front();
            q.pop();
        }
        // return sum;
         if(sum<0)
            return false;
        
        return true;
    }
  
  
    
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
    //   -2 1 4 -1
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = p[i].petrol-p[i].distance;
    }
    
    // return helper(arr[6],6,n,arr);
    for(int i=0;i<n;i++)
    {
        int curr = arr[i];
        if(helper(curr,i,n,arr))
        return i;
    }
       
       return -1;
       
       
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends