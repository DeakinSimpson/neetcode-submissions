class LRUCache {
    int capacity_;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> kvMap_;
    std::list<int> keysUseOrder_;

public:
    LRUCache(int capacity) : capacity_ {capacity}
        {  }
    
    int get(int key) {
        if (kvMap_.find(key) == kvMap_.end()) return -1;
        
        // remove the keysUseOrder at its iterator position
        keysUseOrder_.erase(kvMap_[key].second);

        // push back the keysUserOrder so that the use order is last (MRU)
        keysUseOrder_.push_back(key);

        // update the iterator to be at the end of keysUseOrder
        kvMap_[key].second = --keysUseOrder_.end();

        // return the value
        return kvMap_[key].first;
    }
    
    void put(int key, int value) {
        // if kvMap has the key erase it from the order
        if (kvMap_.find(key) != kvMap_.end())
        {
            keysUseOrder_.erase(kvMap_[key].second);
        } else if (kvMap_.size() == capacity_)
        {   // if the kvMap is at capciry
            // get the lru at the front
            int lru { keysUseOrder_.front() };
            // remove the front
            keysUseOrder_.pop_front();

            // erase the front from the kvMap_
            kvMap_.erase(lru);
        }

        // push the key to the keysUseOrder_
        keysUseOrder_.push_back(key);
        // add the key to the kvMap, with the value iterator pair
        kvMap_[key] = {value, --keysUseOrder_.end() };
    }
};
