//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends




vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
           
           int i=0;
           int j=0;
           list<int> l;
           vector<long long int> ans;
           
           while(i<N && j<N)
           {
               if(A[j]<0)
               l.push_back(A[j]);
               
               if((j-i+1) < K)
               j++;
               else if((j-i+1)==K)
               {
                   if(l.empty())
                   {
                       ans.push_back(0);
                   }
                   else
                   {
                       ans.push_back(l.front());
                        
                        if(l.front() == A[i])
                        l.pop_front();
                   }
                   
                  
                   
                   i++;
                   j++;
               }
           }
           return ans;
 }
----------------------------------------------------
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
            
            
            
               list<long long int> l;
               vector<long long> ans;
               long long int start=0;
               long long int end=0;
               
               while(start<N && end<N)
               {
                   if(A[end]<0)
                       l.push_back(A[end]);
    
                   if(end-start+1<K)
                   end++;
                   else if(end-start+1==K)
                   {
                       if(l.empty())
                       {
                           ans.push_back(0);
                           
                       }
                       else
                       {
                           long long int frontNegitive=l.front();
                           ans.push_back(l.front());
                          
                          if(frontNegitive == A[start])
                           l.pop_front();
                       }
                       start++;
                       end++;
                    }
               }
        return ans; 
                                                 
                                             }