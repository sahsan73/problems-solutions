struct Node {
    int key, val;
    Node *prev, *next;
    Node(int key, int val) : key{key}, val{val}, prev{nullptr}, next{nullptr} {}
};


class LRUCache {
private:
    Node *head, *tail;
    int sz, cp;     // size and capacity of the of the list
    unordered_map<int, Node*> mp;
public:
    LRUCache(int capacity) {
        head = new Node(-1, -1), tail = new Node(-1, -1);
        head->next = tail, tail->prev = head;
        
        sz = 2, cp = capacity+2;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        
        this->put(key, mp[key]->val);
        return mp[key]->val;
    }
    
    void put(int key, int val) {
        // if the key does NOT exist
        if(!mp.count(key)) {
            Node *tmp = new Node(key, val);
            tmp->next = head->next;
            head->next->prev = tmp;
            head->next = tmp;
            tmp->prev = head;
            
            mp[key] = tmp;
            ++sz;
        } else {    // if the key ALREADY exists
            Node *tmp = mp[key];
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            tmp->prev = tmp->next = nullptr;
            --sz;
            
            mp.erase(key);
            delete tmp;
            
            this->put(key, val);
        }
        
        
        // if the current size (sz) exceeds the capacity (cp)
        if(sz > cp) {
            Node *tmp = tail->prev;
            
            tmp->prev->next = tail;
            tail->prev = tmp->prev;
            tmp->prev = tmp->next = nullptr;
            --sz;
            
            mp.erase(tmp->key);
            delete tmp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
