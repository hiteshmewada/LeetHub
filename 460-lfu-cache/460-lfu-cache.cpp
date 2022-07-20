struct Node{
    int key,value,cnt;
    Node *next, *pre;
    Node(int _key, int _val){
        key=_key;value=_val;cnt=1;
    }
};
struct List{
   int size;
    Node *head,*tail;
    List(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->pre=head;
        size=0;
    }
    void addFront(Node *node){
        Node *temp=head->next;
        head->next=node;
        node->next=temp;
        temp->pre=node;
        node->pre=head;
        size++;
    }
    void deleteNode(Node *node){
        Node *tempPre=node->pre;
        Node *tempNext=node->next;
        tempPre->next=tempNext;
        tempNext->pre=tempPre;
        size--;
    }
};
class LFUCache {
    map<int, Node*>keyNode;
    map<int,List*>freqListMap;
    int maxSizeCache;
    int minFreq,curSize;
public:
    LFUCache(int capacity) {
        maxSizeCache=capacity;
        minFreq=0;
        curSize=0;
    }
    void updateFreqListMap(Node *node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);
        if(node->cnt==minFreq and  
           freqListMap[node->cnt]->size==0)
                minFreq++;
        List *nextHigherFreqList=new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()){
            nextHigherFreqList=freqListMap[node->cnt+1];
        }
        node->cnt+=1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt]=nextHigherFreqList;
        keyNode[node->key]=node;
    }
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node *node=keyNode[key];
            int val=node->value;
            updateFreqListMap(node);
            return val;
        }
        return  -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache==0) return ;
        if(keyNode.find(key)!=keyNode.end()){
            Node *node=keyNode[key];
            node->value=value;
            updateFreqListMap(node);
        }
        else{
            if(curSize==maxSizeCache){
                List *list=freqListMap[minFreq];
                keyNode.erase(list->tail->pre->key);
                freqListMap[minFreq]->deleteNode(
                    list->tail->pre);
                curSize--;
            }
            curSize++;
            // new value to be added who was not there
            minFreq=1;
            List *listFreq=new List();
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                listFreq=freqListMap[minFreq];
            }
            Node *node=new Node(key,value);
            listFreq->addFront(node);
            keyNode[key]=node;
            freqListMap[minFreq]=listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */