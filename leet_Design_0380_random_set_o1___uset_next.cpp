class RandomizedSet {
public:
    
    unordered_set<int>  st;
    
    RandomizedSet() {}
    virtual ~RandomizedSet() {}
    
    bool insert(int val)
    {
        if (st.find(val) != st.end())
            return false;
        st.insert(val);
        return true;
    }
    
    bool remove(int val)
    {
        if (st.find(val) == st.end())
            return false;
        st.erase(val);
        return true;
    }
    
    int getRandom()
    {
        int     i;

        i = rand() % (int) st.size();
        return *next(st.begin(), i);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
