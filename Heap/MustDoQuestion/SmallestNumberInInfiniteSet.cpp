//Here you are given a set of 1000 integer 
// that you have to intialise them in smallestInfiniteset


class SmallestInfiniteSet {
     priority_queue<int,vector<int>,greater<int>> minh;
     unordered_map<int,int> mp;
public:
    SmallestInfiniteSet() {
       for(int i=1;i<=1000;i++)
       {
           mp[i]++;
           minh.push(i);
       }
    }
    
    int popSmallest() {
       
            int n = minh.top();
            mp[n]--;
            minh.pop();
            return n;
        
    }
    
    void addBack(int num) {
        
        if(mp[num]==0){
        minh.push(num);
        mp[num]++;
        }

    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */