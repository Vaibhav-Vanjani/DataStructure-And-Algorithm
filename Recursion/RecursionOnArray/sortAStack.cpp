// sort a stack using recursion


// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


stack<int> sort_stack(stack<int> s)
{
    if(s.size() == 1)
    return s;
    
    int temp = s.top();
    s.pop();
    
    stack<int> temp_s = sort_stack(s);
    
    // 2     //1
    // 1     //2
    // 5     //3
    // 3     //5
    
    // 1 3 5 
    vector<int> v;
    while(!temp_s.empty() && (temp_s.top()<temp))
    {
        v.push_back(temp_s.top());
        temp_s.pop();
    }
    temp_s.push(temp);
    
    for(int i=v.size()-1;i>=0;i--)
    {
        temp_s.push(v[i]);
    }
    return temp_s;
}


int main() {
    // Write C++ code
    
    stack<int> s;
    
    s.push(3);
    s.push(5);
    s.push(1);
    s.push(2);
    
    stack<int> ans = sort_stack(s);
    
    while(!ans.empty())
    {
        cout<<ans.top()<<endl;
        ans.pop();
    }
    
    
    return 0;
}