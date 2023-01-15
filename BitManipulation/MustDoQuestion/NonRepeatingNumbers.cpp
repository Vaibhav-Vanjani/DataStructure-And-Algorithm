//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int exor = 0;
        for(int i=0;i<nums.size();i++)
        {
            exor^=nums[i];
        }
        int rightFirstBit= (exor & (-exor));
        // this gives the the right most bit that is one --  //00000100
        // we took this because at this bit the exor of the two element is different
        int first=0;
        int second=0;
       
        //we store the element in first if result in other than 0
        // for ex -> 00000100 & nums[i] gives a no. only when there 1 at that index
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&rightFirstBit)
            {
                first=first^nums[i];
            }
            else 
            {
                second=second^nums[i];
            }
        }
        vector<int> answer;
        
        if(first<second)
        {
            answer.push_back(first);
            answer.push_back(second);
        }
        else
        {
            answer.push_back(second);
            answer.push_back(first);
        }
       return answer;
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends