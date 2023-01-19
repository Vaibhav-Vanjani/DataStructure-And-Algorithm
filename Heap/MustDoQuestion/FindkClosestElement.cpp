class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

	//Donot Apply binary Search 
	//by just seeing it is sorted 
	//it would have become so complex 
	//with binary search

	// sorting or smallest or largest 
	// + K if given in question think of heap

        priority_queue<pair<int,int>> maxh;
        int n = arr.size();
      for(int i=0;i<n;i++)
      {
         maxh.push({abs(arr[i]-x),arr[i]});
         if(maxh.size()>k)
         {
            maxh.pop();
         }
      }

      vector<int> ans(k,0);
      for(int i=k-1;i>=0;i--)
      {
          ans[i]=maxh.top().second;
          maxh.pop();
      }
    sort(ans.begin(),ans.end());
      return ans;
      
    }
};