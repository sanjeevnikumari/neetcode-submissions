class LRUCache {
public:
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> cache;
    int capacity;
    int size;

    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }

    void makeMostRecentlyUsed(int key) {
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first = dll.begin();
    }

    int get(int key) {
        if(!cache.count(key))
            return -1;

        makeMostRecentlyUsed(key);
        return cache[key].second;
    }

    void put(int key, int value) {

        if(cache.count(key)) {
            cache[key].second = value;
            makeMostRecentlyUsed(key);
        } 
        else {

            if(size == capacity) {
                int lru = dll.back();
                dll.pop_back();
                cache.erase(lru);
                size--;
            }

            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            size++;
        }
    }
};