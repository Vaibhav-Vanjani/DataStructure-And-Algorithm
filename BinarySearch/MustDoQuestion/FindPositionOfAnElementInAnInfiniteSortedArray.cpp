//InterView Question

int ElementInInfiniteSortedArray(array nums,target)
{
       int start=0;
       int end=1;
	while(target>=nums[end])
	{
	  start=end;
	  end=2*end;
	}
	// now you have lower and upper bound
	
    ApplyBinarySearch(nums,start,end);
}