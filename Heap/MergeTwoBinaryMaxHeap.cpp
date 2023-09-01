//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
        
    void heapInsert(vector<int> &a,int ele)
    {
        a.push_back(ele);
        int indx = a.size()-1;
        
        while(indx)
        {
            int parent = indx%2 ? (indx/2)-1 : (indx/2);
            
            if(parent>=0 && a[parent]<a[indx])
            {
                swap(a[parent],a[indx]);
                indx=parent;
            }
            else
            return;
        }
    }
    
    void heapify(vector<int> &a,int i,int size)
    {
        int jsbd = a.size();
        
        while(i<size)
        {
            int l = 2*i+1;
            int r = 2*i+2;
            
            if(r<size)
            {
                
                int maxi = max(a[l],a[r]);
            if(maxi>a[i])
              {
                  if(maxi == a[l])
                {
                   swap(a[i],a[l]);
                   i=l;
                }
                else
                {
                  swap(a[i],a[r]);
                   i=r;
                }
              }
              else return;
            }
            else if(l<size and a[l]>a[i])
            {
               swap(a[i],a[l]);
               i=l;
            }
            else return ;
            
        }
        
    }
    
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        int nsz = a.size();
        int mds = b.size();
        
        for(int i=0;i<m;i++)
        {
            heapInsert(a,b[i]);
        }
        
        int s = a.size();
        for(int i=s/2-1;i>=0;i--)
        {
            heapify(a,i,s);
        }
        
        
        return a;
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}

// } Driver Code Ends