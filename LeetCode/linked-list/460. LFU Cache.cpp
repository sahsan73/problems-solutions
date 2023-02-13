#define sz(x) (int)(x).size()

class LFUCache {
private:
    unordered_map<int, list<pair<int,int>>> lruLists;   // (fq, list)
    unordered_map<int, list<pair<int,int>>::iterator> cache;  // (key, iterator)
    unordered_map<int, int> keyFeqs;    // (key, fq)
    int capacity;
    int lf; // least frequency we have

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->lf = 0;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;

        this->put(key, cache[key]->second);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        // if size of the cache exceeds the capacity
        if(!cache.count(key) && cache.size()==capacity) {
            int d_key = lruLists[lf].back().first;
            
            lruLists[lf].pop_back();
            cache.erase(d_key);
            keyFeqs.erase(d_key);
        }

        // if the key does NOT exist
        if(!cache.count(key)) {
            this->lf = 1;
            lruLists[lf].push_front({key, value});
            cache[key] = lruLists[lf].begin();
            keyFeqs[key] = 1;
        } else {    // if the key ALREADY exists
            int currFq = keyFeqs[key];

            // remove this key from current fq's lru list and cache
            auto it = cache[key];
            lruLists[currFq].erase(it);
            cache.erase(key);

            // update the frequency of the key
            ++keyFeqs[key];

            // insert into new fq's lru list
            lruLists[currFq+1].push_front({key, value});
            cache[key] = lruLists[currFq+1].begin();

            // update the value of lf (least frequency)
            if(currFq==lf && lruLists[currFq].size()==0) ++lf;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
