class LFUCache {
    int cap,size,minFreq;
    unordered_map<int,pair<int,int>> m; // key to {value,freq}
    unordered_map<int,list<int>::iterator> mItr; // key to list iteraor
    unordered_map<int,list<int>> fm; // freq to key list
public:
    LFUCache(int capacity) {
        cap=capacity;
        size=0;
    }
    
    int get(int key) {
        if(m.count(key)==0) return -1;
        fm[m[key].second].erase(mItr[key]);
        m[key].second++;
        fm[m[key].second].push_back(key);
        mItr[key]=--fm[m[key].second].end();
        if(fm[minFreq].size()==0) minFreq++;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(cap<=0) return ;
        int storedValue=get(key);
        if(storedValue!=-1){
            m[key].first=value;return;
        }
        if(size>=cap){
            m.erase(fm[minFreq].front());
            mItr.erase(fm[minFreq].front());
            fm[minFreq].pop_front();
            size--;
        }
        m[key]={value,1};
        fm[1].push_back(key);
        mItr[key]=--fm[1].end();
        minFreq=1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */