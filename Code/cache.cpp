//list + unordered_map, list can insert or erase in constant time

//original vector + unordered_map slow
class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        for(int i=0;i<keys.size();i++)
            if(keys[i]==key){
                keys.erase(keys.begin()+i);
                break;
            }
        keys.push_back(key);
        return cache[key];
        
    }
    
    void set(int key, int value) {
        if(cache.find(key)==cache.end()){
            if(cache.size()==capacity){
                cache.erase(keys[0]);
                keys.erase(keys.begin());
            }
        }else{
            for(int i=0;i<keys.size();i++)
                if(keys[i]==key){
                    keys.erase(keys.begin()+i);
                    break;
            }
        }
        keys.push_back(key);
        cache[key] = value;
    }
private:
    unordered_map<int,int> cache;
    vector<int> keys;
    int capacity;
};
