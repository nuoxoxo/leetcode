class RandomizedSet {
public:

    unordered_set<int> S;

    RandomizedSet() {}
    
    bool insert(int val) {
        if (S.find(val) != S.end())
            return false;
        S.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (S.find(val) == S.end())
            return false;
        S.erase(val);
        return true;
    }
    
    int getRandom() {
        return *next(S.begin(), rand() % S.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
