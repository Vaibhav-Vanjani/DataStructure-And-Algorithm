class MedianFinder {
public:

// 2-1/2 + 2/2

   priority_queue<int> maxh;
   priority_queue<int,vector<int>,greater<int>> minh;
   
    int size;


    MedianFinder() {

        size=0;
    }
    
    void addNum(int num) {

    maxh.push(num);
    int b = maxh.top();
    maxh.pop();
    minh.push(b);

    if(minh.size()>maxh.size())
    {
        int a = minh.top();
        minh.pop();
        maxh.push(a);
    }     

    }
    
    double findMedian() {

      if(minh.size() == maxh.size())
      {
          int a = minh.top();
          int b = maxh.top();
          
          return ((double)a + (double)b)/2.0;
      }
      else
      {
          int b = maxh.top();
          return double(b);
      }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */