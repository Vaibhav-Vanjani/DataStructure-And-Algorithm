class Solution {
public:
    int findMin(vector<int>& nums) {
        
            //    prev > mini < next 


            //    prev  = (n+i-1)%n;

            //    0  (n-1 + 0)%n == 1
            //    1  (n-1+1)%n
            //    2  (n-1+2)%n

            //    next 

            //    n-1   (i+1)%n;
            //    3    (n-1-3)%n

            //  3  4() 
// // 
//             1 2 3 4 5 left
//             5 1 2 3 4 left
//             4 5 1 2 3 ans
//             3 4 5 1 2 right
            
//             2 3 4 5 1 right


//             1 2



            int start =0;
            int end=nums.size()-1;
            int n = end+1;

            while(start<=end)
            {
               

                int mid = start+(end-start)/2;
                 int prev = (n+mid-1)%n;
                int next = (mid+1)%n;

                if(nums[mid]<=nums[next] && nums[mid]<=nums[prev])
                {
                    return nums[mid];
                }
                else 
                {
                    if(nums[mid]>=nums[start] && nums[mid]>nums[end])
                    {
                        start = mid+1;
                    }
                    else
                    {
                        end = mid -1;
                    }
                }
                 
            }

            return 0;

    }
};
---------------------------------

//revisited : 
1.
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	  
	  
// 	  12345

// 	  51

// 	  45123
// 	  34512
// 	  23451
	  int start =0;
	  int end =n-1;
	  
	  
	  while(start<=end)
	  {
	      int mid=start+(end-start)/2;
	      int prev = (mid-1+n)%n;
	      int next = (mid+1+n)%n;
	      
	      if(arr[mid]<=arr[prev] && arr[mid]<=arr[next])
	      return mid;
	      
	      
	      if(arr[mid]>=arr[start] && arr[mid]>=arr[end])
	      {
	          start=mid+1;
	      }
	      else
	      {
	          end=mid-1;
	      }
	  }
	  
	  

	   
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	   // code here
	   //  12345
	     
	  
// 	  minimum element in rotated sorted array
// prev = mid+n-1%n ;
// next=mid+1%n;

// 1 .  mid<prev && mid<next 
// 2 . take decision where you have to go.


if(n==1)
return 0;

int start=0;
int end=n-1;
while(start<=end)
{
    int mid=start+(end-start)/2;
    int prev=(mid-1+n)%n;
    int next=(mid+1+n)%n;
    
    if(arr[mid]<arr[prev] && arr[mid]<arr[next])
    {
        return mid;
    }
    else if(arr[mid]>=arr[start] && arr[mid]>=arr[end])
    {
        start=mid+1;
    }
    else
    {
     end=mid-1;   
    }
}


 




	   
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends