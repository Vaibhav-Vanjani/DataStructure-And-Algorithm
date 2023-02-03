//Gives TLE Recursive approach
long long player1=0;
long long player2=0;

    // main line: 
 // if player 1 wins either player2 choose from start from end 
    // then only return true

class Solution {
public:


   bool getAns(int start,int end,vector<int> nums,bool decide)
    {
        if(start>end)
        {
            if(player1>=player2)return true;
            else return false;
        }

        if(decide)
      {  player1+=nums[start];
        bool opt1 = getAns(start+1,end,nums,false);
        player1-=nums[start];

        if(opt1)return true;

        player1+=nums[end];
        bool opt2 = getAns(start,end-1,nums,false);
         player1-=nums[end];

        if(opt2)return true;
      }
      else
      {
           player2+=nums[start];
        bool opt3 = getAns(start+1,end,nums,true);
        player2-=nums[start];
       

        player2+=nums[end];
        bool opt4 = getAns(start,end-1,nums,true);
        player2-=nums[end];

        if(opt3 && opt4)return true; // if player 1 wins either player2 choose from start from end 
      }

   return false;
       

    }


    bool PredictTheWinner(vector<int>& nums) {
        
        int n=nums.size();

        return getAns(0,n-1,nums,true);
    }
};