class MyStack {
    queue<int>q1,q2;
    int top_e=-1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        top_e=x;
    }
    
    int pop() {
        while(q1.size()>1){
            top_e=q1.front();
            q1.pop();
            q2.push(top_e);
        }
        queue<int>temp;
        int ele=q1.front();
        q1.pop();
        q1=q2;
        q2=temp;
        return ele;
    }
    
    int top() {
        return top_e;
    }
    
    bool empty() {
        if(q1.size()) return false;
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */