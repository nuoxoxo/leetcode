class TimeMap {
private:
    unordered_map<string, map<int, string, greater<int>>> mp;
public:
    TimeMap()
    {}
    
    void set(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp)
    {
        map<int, string>::iterator it;

        if (mp.find(key) == mp.end())
            return "";
        it = mp[key].lower_bound(timestamp);
        if (it == mp[key].end())
            return "";
        return it->second;
    }
};
