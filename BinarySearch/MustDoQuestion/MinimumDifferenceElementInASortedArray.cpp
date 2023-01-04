int MinimumDifferenceElementinaSortedArray(vector<int> arr,int n,int target)
{
      imp property
    // after applying binary search we end up at arr[start] and arr[end] which are neighbour of target
      
   // we can also find floor and ceil of target and then can get Minimum Difference Element 

  	while(start<=end)
  	{
         	if(arr[mid]==target)
		return arr[mid];
		else if(arr[mid]<target)
		start=mid+1;
		else
		end=mid-1;
	}

	int firstNeighbour = abs(arr[start]-target);
	int secondNeighbour = abs(arr[end]-target);
	 if(firstNeighbour>secondNeighbour)
	return arr[end];
	else
	return arr[start];

}