class MedianFinder {
public:
   priority_queue<int>mx;
    priority_queue<int,vector<int>,greater<int>>mn;
    MedianFinder() {
        // v.clear();
    }
    
    void addNum(int num) {
        if(mx.empty() or mx.top()>num) mx.push(num);
        else mn.push(num);
        if(mx.size()>mn.size()+1){
            mn.push(mx.top());
            mx.pop();
        }
        else if(mn.size()>mx.size()+1){
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    double findMedian() {
        if(mx.size()==mn.size()){
            return (mx.top()+mn.top())/2.0;
        }
        else {
            if(mx.size()>mn.size()) return mx.top();
            else return mn.top();
        }
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */