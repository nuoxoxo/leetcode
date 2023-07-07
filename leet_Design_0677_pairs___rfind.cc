class MapSum {

unordered_map<string, int>  M;

public:
    MapSum() {
        
    }
    
    void insert(string key, int val)
    {
        M[key] = val;
    }
    
    int sum(string prefix)
    {
        int res = 0;
        for (pair<string, int> p: M)
        {
            if (p.first.rfind(prefix, 0) != std::string::npos)
            {
                res += p.second;
            }
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
