#include <bits/stdc++.h> 


vector<int> mergeF (vector<int> &a, vector<int> &b)
{
    vector<int> c;

    int n = a.size();
    int m = b.size();
    int i=0;
    int j=0;

    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else
        {
          c.push_back(b[j]);
            j++;
        }
    }

     while(i<n)
    {
        
            c.push_back(a[i]);
            i++;
    }

     while(j<m)
    {
       
          c.push_back(b[j]);
            j++;
    }

    return c;

}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    int n = kArrays.size(); 
    vector<int> merge = kArrays[0];

    for(int i=1;i<k;i++)
    {
        merge = mergeF(merge,kArrays[i]);
    }
    return merge;
}
