class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
    int start=0;
    int n=arr.size();
    int end=n-1;

    // 1 2 3 4 5 4 3

    // edge case 
    // check your answer with size == 2
    // because this condition can arise in binary search case 

    // [3,5,3,2,0]
    while(start<=end)
    {
        int mid =start + (end-start)/2;

        if((mid!=0 && arr[mid]>arr[mid-1]) && ((mid+1)!=n && arr[mid]>arr[mid+1]))
        return mid;
        else if(((mid-1) >=0 && arr[mid]>arr[mid-1]))
        start=mid+1;
        else if((mid+1)<n && arr[mid]>arr[mid+1])
        end=mid-1;
        else 
        {
            if(mid==0)
            start=mid+1;
            else if(mid== n-1)
            end=mid-1;
        }
    }
    return -1;

    }
};