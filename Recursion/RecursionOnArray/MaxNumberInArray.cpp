//{ Driver Code Starts

//Maximum No. using recursion 

#include <bits/stdc++.h>
using namespace std;

int maxi=INT_MIN;

void helper(vector<int> &v,int i)
{
    if(i==v.size())return ;
    
    maxi = max(v[i],maxi);
    helper(v,i+1);
}



int main() {
    // Write C++ code here
    
    vector<int> v;
    
    v.push_back(200);
    v.push_back(922);
    v.push_back(3);
    v.push_back(1);
    v.push_back(96);
    
    
    helper(v,0);
    
    
  cout<<maxi;
    
    return 0;
}
