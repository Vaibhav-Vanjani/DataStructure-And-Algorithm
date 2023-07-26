// delete element when passing its index of stack

#include<bits/stdc++.h>
using namespace std;

void deleteFrom(stack<int> &s,int indx)
{
    if(s.size() == indx)
    {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    
    deleteFrom(s,indx);
    
    s.push(temp);
}


int main()
{
    
    stack<int> s;
    
    s.push(3);
    s.push(5);
    s.push(1);
    s.push(2);
    s.push(4);
    
    deleteFrom(s,3);
    
    
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
