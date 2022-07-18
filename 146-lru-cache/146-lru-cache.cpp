class LRUCache {
public:
    class Node{
        public:
        int key,value;
        Node *next,*pre;
        Node(int _key, int _val){
            key=_key;
            value=_val;
        }
    };
    Node *head=new Node(-1,-1),*tail=new Node(-1,-1);
    int cap;
    map<int,Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->pre=head;
    }
    void addNode(Node *temp){
        Node *headNext=head->next;
        head->next=temp;
        temp->next=headNext;
        headNext->pre=temp;
        temp->pre=head;
    }
    void deleteNode(Node *temp){
        Node *previousNode=temp->pre;
        Node *nextNode=temp->next;
        previousNode->next=nextNode;
        nextNode->pre=previousNode;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node *temp=mp[key];
        int res=temp->value;
        mp.erase(key);
        deleteNode(temp);
        addNode(temp);
        mp[key]=head->next;
        return res;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node *temp=mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size()==cap){
            mp.erase(tail->pre->key);
            deleteNode(tail->pre);
        }
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */