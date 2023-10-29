class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {

      int pigs = 0;
      int trial = minutesToTest/minutesToDie;
    while (pow((trial+1),pigs)< buckets)
        pigs += 1;
        
    return pigs;
    }
};