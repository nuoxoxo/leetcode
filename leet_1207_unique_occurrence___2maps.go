class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> mp;
        unordered_set<int>      st;

        for (int& n: arr)
            mp[n]++;
        for (int& n: arr)
            st.insert(mp[n]);
        return (mp.size() == st.size());
    }
};
