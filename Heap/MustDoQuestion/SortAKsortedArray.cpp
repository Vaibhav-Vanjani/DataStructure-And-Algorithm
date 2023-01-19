---
1st Method -> heap 

(O(nlogK))-- TC
(O(N)) -- SC

2nd method --> Insertion Sort
(O(nlogK))-- TC
(O(1)) -- SC

    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        
        priority_queue<int,vector<int>,greater<int>> minh;
        vector<int> answer;
        for(int i=0;i<num;i++)
        {
            minh.push(arr[i]);
            if(minh.size()>K)
            {
                answer.push_back(minh.top());
                minh.pop();
            }
        }
        
        while(minh.size())
        {
            answer.push_back(minh.top());
            minh.pop();
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends