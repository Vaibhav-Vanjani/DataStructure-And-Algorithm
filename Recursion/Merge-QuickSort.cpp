// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;



int partition(int start,int end,vector<int> &v)
{
    int size=v.size();
    
    int pivot = v[start];
    int count=0;
    
    //count elements less than pivot
    for(int i=start+1;i<=end;i++)
    {
            if(v[i]<=pivot)
            count++;
    }
    
    // pivot Index
    int pivotIndex = start+count;
    
    //swap pivot with v[pivotIndex]
    int temp = v[start];
    v[start]=v[pivotIndex];
    v[pivotIndex]=temp;
    
    int i=start;
    int j=end;
    
    //elements less than v[pivotIndex] should be at left
    //elements greater than v[pivotIndex] should be at right
    while(i<pivotIndex && j>pivotIndex)
    {
        while(v[i]<v[pivotIndex])
        {
            i++;
        }
        while(v[j]>v[pivot])
        {
            j--;
        }
        
        if(i<pivotIndex && j>pivotIndex)
        {
            swap(v[i++],v[j--]);
        }
    }
    return pivotIndex;
}




void quickSort(int start,int end,vector<int> &v)
{
    if(start<end)
    {
        int pi = partition(start,end,v);
        
        quickSort(start,pi-1,v);
        quickSort(pi+1,end,v);
    }
}


// mergeSort
// void merge(int start,int mid,int end,vector<int> &v)
// {
//     int x =v.size();
    
//     int n = mid+1-start;
//     int m = end -mid;
    
//     int a[n];
//     int b[m];
    
//     for(int i=0;i<n;i++)
//     {
//         a[i]=v[i+start];
//     }
    
//     for(int j=0;j<m;j++)
//     {
//         b[j]=v[j+mid+1];
//     }
    
//     int i=0,j=0,k=0;
    
//     while(i<n && j<m)
//     {
//         if(a[i]<=b[j])
//         {
//             v[k+start]=a[i];
//             i++;
//         }
//         else
//         {
//              v[k+start]=b[j];
//              j++;
//         }
//         k++;
//     }
    
//     while(i<n)
//     {
//         v[k+start]=a[i];
//             i++;
//             k++;
//     }
    
//     while(j<m)
//     {
//         v[k+start]=b[j];
//             j++;
//             k++;
//     }
// }

// void mergeSort(int start,int end,vector<int> &v)
// {
    
//     if(start<end)
//     {
//         int mid = start + (end-start)/2;
//         mergeSort(start,mid,v);
//         mergeSort(mid+1,end,v);
//         merge(start,mid,end,v);
//     }
// }


int main() {
   
   int n;
   cin>>n;
   
  vector<int> v(n,0);

    for(int i=0;i<v.size();i++)
    cin>>v[i];
   
   
//   mergeSort(0,n-1,v);
    quickSort(0,n-1,v);

    for(int i=0;i<v.size();i++)
    cout<<v[i]<<endl;

    return 0;
}