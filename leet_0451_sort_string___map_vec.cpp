class Solution {
public:
    string frequencySort(string s)
    {
        unordered_map<char, int>    mp;
        vector<pair<char, int>>     a;
        string                      r;
        int                         i;

        for (char & c: s)
            mp[c]++; 
        for (pair<char, int> it: mp)
            a.push_back(it);
        sort(a.begin(), a.end(),
             [](pair<char, int> p1, pair<char, int> p2)
             { return p1.second > p2.second ; });
        for (pair<char, int> & p: a)
        {
            i = -1;
            while (++i < p.second)
                r += p.first;
        }
        return r;
    }
};
