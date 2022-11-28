class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        map<int, int>           w, l;
        map<int, int>::iterator it;
        vector<int>             r1, r2;
        // vector<int, int>    res;

        for (vector<int>& m : matches)
        {
            w[m[0]]++;
            l[m[1]]++;
        }
        it = w.begin();
        while (it != w.end())
        {
            if (l.find(it->first) == l.end())
                r1.push_back(it->first);
            ++it;
        }
        it = l.begin();
        while (it != l.end())
        {
            if (it->second == 1)
                r2.push_back(it->first);
            ++it;
        }
        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());
        return {r1, r2};
    }
};
