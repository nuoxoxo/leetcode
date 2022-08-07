class MyHashSet {
public:
    
    vector<int> v;
    
    MyHashSet() {
    }
    
    void add(int key)
    {
        if (find(v.begin(), v.end(), key) != v.end())
            return;
        v.push_back(key);
    }
    
    void remove(int key)
    {
        v.erase(std::remove(v.begin(), v.end(), key), v.end());
    }
    
    bool contains(int key)
    {
        return find(v.begin(), v.end(), key) != v.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
