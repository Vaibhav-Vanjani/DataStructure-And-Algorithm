#include <bits/stdc++.h>
using namespace std;


int sum (int n)
{
    if(n==0)
    {
        return 0;
    }
    
    return n+ sum(n-1);
}

int fib(int n)
{
    if(n==0)return 0;
    if(n==1) return 1;
    
    return fib(n-1)+fib(n-2);
}

int fact(int n)
{
    if(n==0)return 0;
    if(n==1)return 1;
    
    return n*fact(n-1);
}

int main() {
    
    // Sum from 1 to n
    int n;
    cin>> n;
    cout<<"Sum from 1 to"<<n<<"is :";
    cout<<sum(n)<<endl;
    
    // factorial from 1 to n
    cout<<"factorial of"<<n<<"is :";
    cout<<fact(n)<<endl;
    
    // fibonacci for nth term
    cout<<"fibonacci for" <<n<<"term" ;
    cout<<fib(n)<<endl;
    
    
    return 0;
}
       

