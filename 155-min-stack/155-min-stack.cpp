class MinStack {
public:
    stack<long long>st;
    long long mn=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        long long value=val;
        if(st.empty()) {mn=val;st.push(value);}
        else 
        {
            if(value<mn){
                
                st.push(2*value-mn);
                mn=value;
            }
            else st.push(value);
        }
       // st.push({val,mn});
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top()>=mn) st.pop();
        else{
            int val=st.top();
            mn=2*mn-val;
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        if(st.top()<mn) return mn;
       return st.top();
    }
    
    int getMin() {
        return mn;
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