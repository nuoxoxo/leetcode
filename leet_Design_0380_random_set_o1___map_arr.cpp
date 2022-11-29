class RandomizedSet {
public:
    
    //  storing devices
    
    unordered_map<int, int> mp; // searching an u_map is an O(1) operation 
    vector<int>             a;  // val vs. its index in mp

    
    RandomizedSet() {}
    virtual ~RandomizedSet() {}
    
    bool insert(int val)
    {
        if (mp.find(val) != mp.end())
            return false;
        a.push_back(val);
        mp[val] = (int) a.size() - 1;
        return true;
    }
    
    bool remove(int val)
    {
        if (mp.find(val) == mp.end())
            return false;

        unordered_map<int, int>::iterator   it;
        int                                 idx, replacement;

        //  Get the index of val in map

        it = mp.find(val);
        idx = it->second;
        
        // cout << it->first << ' ' << idx << endl;

        //  Replace the item at this index with the last item in the value array

        a[idx] = a.back();
        

        //  Update the replacement's index in map as well

        replacement = a[idx];
        mp[replacement] = idx;

        //  remove the val (key) from map
        //  a.back() has been copied to a[i], should be deleted

        mp.erase(val);
        a.pop_back();
        return true;
    }
    
    int getRandom()
    {

        //  int rand()

        return (a[rand() % (int) a.size()]);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
