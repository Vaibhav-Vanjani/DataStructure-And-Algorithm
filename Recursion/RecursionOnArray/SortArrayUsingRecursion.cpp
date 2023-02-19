
// SortArrayUsingRecursion

#include <bits/stdc++.h>
using namespace std;


void helper(vector<int> &v)
{
    int size =v.size();
    
    if(size==1 or size==0)return;
    
    int temp = v[0];
    v.erase(v.begin());
    
    helper(v);
    
    int n = v.size();
    while(n>0 && v[n-1]>temp)
    {
        n-=1;
    }
    v.insert(v.begin()+n,temp);
}



int main() {
    // Write C++ code here
    
    vector<int> v;
    
    v.push_back(2);
    v.push_back(9);
    v.push_back(3);
    v.push_back(1);
    v.push_back(96);
    
    
    helper(v);
    
    
    for(int i=0;i<v.size();i++)cout<<v[i];
    
    return 0;
}
