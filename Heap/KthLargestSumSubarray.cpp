#include<queue> 
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	int n = arr.size();
	long long sum=0;
	vector<long long> v;
	for(int i=0;i<n;i++)
	{
		sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=arr[j];
			v.push_back(sum);
		}
	}

	n=v.size();
	 
	priority_queue <long long,vector<long long>,greater<long long>> pq;
	for(int i=0;i<n;i++)
	{
		pq.push(v[i]);

		if(pq.size()>k)
		pq.pop();
	}

	return pq.top();

	
}