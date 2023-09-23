// } Driver Code Ends
//User function template for C++
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
  vector<int> rank,parent,size;
 public:
  DisjointSet(int n)
  {
      rank.resize(n+1,0);
     parent.resize(n+1);
     size.resize(n+1,1);
      cout<<"constructor Called"<<endl;
     for(int i=0;i<n;i++)
      {
          parent[i]=i;
      }
  }
  
  int findParent(int node)
  {
      if(parent[node]==node)
      {
          return node;
      }
      
      return parent[node] = findParent(parent[node]);
  }
  
  
  void unionByRank(int u,int v)
  {
      int ulp_u = findParent(u);
      int ulp_v = findParent(v);
      
      if(ulp_u==ulp_v)return;
      
      if(rank[ulp_u] == rank[ulp_v])
      {
          parent[ulp_u] = ulp_v;
          rank[ulp_v]+=1;
      }
      else if(rank[ulp_u] < rank[ulp_v])
          parent[ulp_u]=ulp_v;
      else
           parent[ulp_v]=ulp_u;
      
  }
  
  void unionBySize(int u,int v)
  {
      int ulp_u = findParent(u);
      int ulp_v = findParent(v);
      
      if(ulp_u==ulp_v)return;
      
      if(size[ulp_u] < size[ulp_v])
      {
          parent[ulp_u] = ulp_v;
          size[ulp_v]+=size[ulp_u];
      }
      else 
      {
           parent[ulp_v] = ulp_u;
          size[ulp_u]+=size[ulp_v];
      }
      
  }
  
  
  
  
  
};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    
    
    if(ds.findParent(3) == ds.findParent(7))
    cout<<"same";
    else
    cout<<"not same";
    
    ds.unionByRank(3,7);
    cout<<endl;
    
    if(ds.findParent(3) == ds.findParent(7))
    cout<<"same";
    else
    cout<<"not same";


    return 0;
}

