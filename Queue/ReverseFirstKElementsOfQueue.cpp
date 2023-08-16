//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends




// User function Template for C++

// Function to reverse first k elements of a queue.
void rev(deque<int> &dq)
{
    if(dq.size()==1)
    return;
    
    int i=dq.front();
    dq.pop_front();
    rev(dq);
    dq.push_back(i);
}


void helper(deque<int> &dq,int k)
{
    if(k==0)
    {
        rev(dq);
        return;
    }
    
    int i=dq.back();
    dq.pop_back();
    helper(dq,k-1);
    dq.push_back(i);
}


queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    int n=q.size();
    deque<int> dq;
    while(!q.empty())
    {
        dq.push_back(q.front());
        q.pop();
    }
    
    helper(dq,n-k);
    
    while(!dq.empty())
    {
        q.push(dq.front());
        dq.pop_front();
    }
    
    return q;
    
}