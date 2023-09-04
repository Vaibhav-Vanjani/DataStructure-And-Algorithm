class Solution {
public:

    int nthUglyNumber(int n) {

  int dp[n+1];
  dp[0]=1;
  int p1=0,p2=0,p3=0;

  for(int i=1;i<=n;i++)
  {
      int t2 = dp[p1]*2;
      int t3 = dp[p2]*3;
      int t5 = dp[p3]*5;

      int mini = min(t2,min(t3,t5));
      dp[i]=mini;

      if(mini == t2)p1++;
      if(mini == t3)p2++;
      if(mini == t5)p3++;      
  }

  return dp[n-1];

        
    }
};