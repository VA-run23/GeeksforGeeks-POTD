class LRUCache {
  private:
  public:
  
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) : capacity(cap){}
        // code here
    

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
         if (!map.count(key)) return -1;
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
         if (map.count(key)) cache.splice(cache.begin(), cache, map[key]), map[key]->second = value;
        else {
            if (cache.size() == capacity) map.erase(cache.back().first), cache.pop_back();
            cache.emplace_front(key, value), map[key] = cache.begin();
        }
    }
};
