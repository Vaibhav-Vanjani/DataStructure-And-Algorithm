class MinStack {
public:
        long long minEle;
        stack<long long> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())minEle=val;

        if(val>=minEle)
        st.push(val);
        else{
        st.push(((1LL*2*val) - minEle));
        minEle=val;}
    }
    
    void pop() {
       if(st.top()>=minEle)
        st.pop();
        else
        {
            minEle = (1LL*2*minEle)-st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top()<minEle)
        return minEle;
        
        return st.top();
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */