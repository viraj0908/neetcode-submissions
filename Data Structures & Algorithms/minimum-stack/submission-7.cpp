class MinStack {
    stack<long> st;
    long min;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(0);
            min=val;
        }
        else{
            long diff=val-min;
            st.push(diff);
            if(diff<0) min=val;
        }
        return;
    }
    
    void pop() {
        if(st.empty()) return;
        long x=st.top();
        st.pop();
        if(x<0) min=min-x;
        return;
    }
    
    int top() {
        long x=st.top();
        if(x>=0) return x+min;
        else return min;
    }
    
    int getMin() {
        return min;
    }
};
