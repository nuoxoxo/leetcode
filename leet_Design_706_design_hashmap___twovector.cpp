class MyHashMap {
public:
    
    vector<int> keys;
    vector<int> vals;
    
    MyHashMap() {}
    
    void put(int key, int value)
    {
        int i = -1;
        while (++i < keys.size())
        {
            if (keys[i] == key)
            {
                vals[i] = value;
                return ;
            }
        }
        keys.push_back(key);
        vals.push_back(value);
    }
    
    int get(int key)
    {
        int i = -1;
        while (++i < keys.size())
        {
            if (keys[i] == key)
                return vals[i];
        }
        return -1;
    }
    
    void remove(int key)
    {
        int i = -1;
        while (++i < keys.size())
        {
            if (keys[i] == key)
            {
                keys.erase(keys.begin() + i);
                vals.erase(vals.begin() + i);
                break;
            }
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
