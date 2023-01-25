class Solution {
public:

   int getMaxConsecutiveAns(string answerKey,int k,char C)
   {
       int N= answerKey.size();
       int count =0;
       int start=0;
       int end=0;
       int ans=0;
       char c=C;

       while(end<N)
       {  if(answerKey[end]==c)
          count++;

          while(count>k)
          {
              if(answerKey[start]==c)
              count--;

              start++;
          }

          ans=max(end-start+1,ans);
          end++;
       }

       return ans;
   }



    int maxConsecutiveAnswers(string answerKey, int k) {

// easy way logic same
// 1st method
// logic
// Tcount = take out maximum consecutive t with k flip
// Fcount = take out maximum consecutive f with k flip

// return max(tcount,fcount);


return max(getMaxConsecutiveAns(answerKey,k,'T'),getMaxConsecutiveAns(answerKey,k,'F'));


    }
};