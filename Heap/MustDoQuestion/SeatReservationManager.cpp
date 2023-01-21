class SeatManager {
public:
    unordered_map<int,int> mp;
    priority_queue<int,vector<int>,greater<int>> minh;

	//idea is to push all unreserved seat to minheap 
	// !mp[i] mean ith seat is unreserved
	// mp[i] =1 means ith seat is reserved
    SeatManager(int n) {
    for(int i=1;i<=n;i++)
    {
        minh.push(i);
    }
    }

    
    int reserve() {
        int top = minh.top();
        mp[top]=1;
        minh.pop();
        return top;
    }
    
    void unreserve(int seatNumber) {
        mp[seatNumber]=0;
        minh.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */