class LRUCache {
private:
    list<pair<int,int>> ls;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    int capacity; 
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        ls.splice(ls.begin(), ls, mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        // if the key does NOT exist
        if(!mp.count(key)) {
            ls.push_front(make_pair(key, value));
            mp[key] = ls.begin();
        } else {    // if the key ALREADY exists
            mp[key]->second = value;
            ls.splice(ls.begin(), ls, mp[key]);
        }

        // if the current size of the list exceeds the limit
        if((int)ls.size() > capacity) {
            auto d_key = ls.back();
            ls.pop_back();
            mp.erase(d_key.first);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
