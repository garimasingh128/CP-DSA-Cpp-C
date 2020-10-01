class LRUCache {
public:
    int cap;
    list<int> el;
    unordered_map<int,int> m;
    LRUCache(int capacity) {
        cap=capacity;
    }

    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        el.remove(key);
        el.push_back(key);
        return m[key];

    }

    void put(int key, int value)
    {
        if(m.find(key)!=m.end())
        {
            el.remove(key);
            m.erase(key);
        }
        if(el.size()==cap)
        {
            int temp = el.front();
            el.pop_front();
            m.erase(temp);
        }
        m[key] = value;
        el.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
