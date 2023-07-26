//sort an array using recursion

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

vector<int> sort_rec(vector<int> ans)
{
    if(ans.size()==1)return ans;
    
    int temp = ans[ans.size()-1];
    ans.erase(ans.begin()+ans.size()-1);
    
    // 5 1 2

    vector<int> x = sort_rec(ans);
    // temp = 3;
    // 1 2 5
    int i=x.size()-1;
    for(;i>=0;i--)
    {
        if(x[i]<temp)
        {
            x.insert(x.begin()+i+1,temp);
            break;
        }
    }
    
    if(i<0)x.insert(x.begin()+i+1,temp);
    // cout<<temp<<endl;
    return x;
    
  
     
}

int main() {
    // Write C++ cod
    
    vector<int> ans = {3,5,1,2};
    
    vector<int> ans_arr = sort_rec(ans);
    
    for(int i=0;i<ans_arr.size();i++)
    {
        cout<<ans_arr[i]<<" "; 
    }
    
    return 0;
}
--------------------------------------------------------

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
