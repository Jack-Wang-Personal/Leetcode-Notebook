struct DListNode{
    int key;
    int val;
    DListNode* prev;
    DListNode* next;
    DListNode():key(0),val(0),prev(nullptr),next(nullptr){}
};
class LRUCache {
unordered_map<int,DListNode*> cache;
DListNode* head;
DListNode* tail;
int capacity;
int size;

public:
    LRUCache(int _capacity) {
        head=new DListNode();
        tail=new DListNode();
        capacity=_capacity;
        size=0;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int _key) {
        if(cache.count(_key)){
            DListNode* use=cache[_key];
            remove(use);
            add2tail(use);
            return use->val;
        }else{
            return -1;
        }
        
    }
    
    void put(int _key, int _value) {
        if(cache.count(_key)){
            DListNode* use=cache[_key];
            remove(use);
            add2tail(use);
            use->val=_value;
        }else{
            if(size==capacity){
                pop();
                size--;
            }
            DListNode* node=new DListNode();
            node->key=_key;
            node->val=_value;
            cache[_key]=node;
            add2tail(node);
            size++;
        }
        
    }
    void remove(DListNode* d){
        d->prev->next=d->next;
        d->next->prev=d->prev;
    }
    void add2tail(DListNode* d){
        d->next=tail;
        d->prev=tail->prev;
        tail->prev->next=d;
        tail->prev=d;
    }
    void pop(){
        DListNode* d=head->next;
        remove(d);
        cache.erase(d->key);
        delete d;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */