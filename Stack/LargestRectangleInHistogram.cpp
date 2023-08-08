class Solution {
public:

    vector<int> rightIndexSmaller(vector<int> price)
    {
        int n = price.size();
        vector<int> ans;
        stack<pair<int,int>> st;
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            ans.push_back(n);
            else
            {   
                if(price[i]<=st.top().first)
                {
                    while(!st.empty() && price[i]<=st.top().first)
                    st.pop();   

                    if(st.empty())
                    ans.push_back(n);
                    else
                    ans.push_back(st.top().second);
                }
                else
                    ans.push_back(st.top().second);
            }
            st.push({price[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


vector<int> leftIndexSmaller(vector<int> price)
    {
        int n = price.size();
        vector<int> ans;
        stack<pair<int,int>> st;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            ans.push_back(-1);
            else
            {   
                if(price[i]<=st.top().first)
                {
                    while(!st.empty() && price[i]<=st.top().first)
                    st.pop();   

                    if(st.empty())
                    ans.push_back(-1);
                    else
                    ans.push_back(st.top().second);
                }
                else
                    ans.push_back(st.top().second);
            }
            st.push({price[i],i});
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }



    int largestRectangleArea(vector<int>& heights) {
        

        vector<int> nlr = rightIndexSmaller(heights);
        vector<int> nll = leftIndexSmaller(heights);

        int size=nlr.size();
        int size2=nll.size();
        // return nlr[0];
        long long ans = -1;
        int n = heights.size();
        for(int i=0;i<n;i++)
        {
            ans = max(ans,1LL*heights[i]*(nlr[i]-nll[i]-1));
        }
        return ans;
    }
};