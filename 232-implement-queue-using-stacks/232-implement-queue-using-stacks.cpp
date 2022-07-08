class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int>st1,st2;
         st1.push(x);
        while(st.size()){
            st2.push(st.top());
            st.pop();
        }
         while(st2.size()){
            st1.push(st2.top());
            st2.pop();
        }
        st=st1;
    }
    
    int pop() {
       int a=st.top();
        st.pop();
        return a;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        if(st.size()) return false;
        return true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */