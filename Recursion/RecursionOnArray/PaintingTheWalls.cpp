class Solution {
private:
    long elper(int i,int costtaken,int takentime,vector<int>& cost, vector<int>& time,int &ans,int n,long dp[501][501])
    {
           if(takentime>=n)
            return 0;
          if(i>=n)
            return INT_MAX;
      
    if(dp[i][takentime] != -1)return dp[i][takentime];  
   
    return dp[i][takentime] = min(elper(i+1,costtaken,takentime,cost,time,ans,n,dp),elper(i+1,costtaken,takentime+1+time[i],cost,time,ans,n,dp)+cost[i]);
     }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
   
    int ans=INT_MAX;
    int n = cost.size();
    long dp[501][501];memset(dp,-1,sizeof(dp));
    return elper(0,0,0,cost,time,ans,n,dp);
    
   }
};