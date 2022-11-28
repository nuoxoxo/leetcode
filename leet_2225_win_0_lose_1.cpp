class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m)
    {
        vector<vector<int>>     res;
        vector<int>             r1, r2;
        set<int>                all;
        set<int>                lset;
        map<int, int>           lmap;
        map<int, int>::iterator it;

        for (vector<int> a : m)
        {
            all.insert(a[0]);
            all.insert(a[1]);
            lset.insert(a[1]);
            lmap[a[1]]++;
        }

        set_difference(all.begin(), all.end(), 
			lset.begin(), lset.end(), 
			inserter(r1, r1.end()));
        res.push_back(r1);
        it = lmap.begin();
        while (it != lmap.end())
        {
            if (it->second == 1)
                r2.push_back(it->first);
            it++;
        }
        res.push_back(r2);
        return res;
    }
};
