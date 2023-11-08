class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
       if(fx==sx && fy==sy && t==1)return false;
        return max(abs(fx-sx),abs(fy-sy)) <= t;
    }
};