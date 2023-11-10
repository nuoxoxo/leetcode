class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
    {
        unordered_map<int, vector<int>> D;
        unordered_map<int, int> idg;
        for (vector<int> & v: adjacentPairs)
        {
            int a = v[0], b = v[1];
            D[a].push_back(b);
            D[b].push_back(a);
            idg[a]++;
            idg[b]++;
        }
        int key;
        for (auto it: idg)
        {
            if (it.second == 1)
                key = it.first;
        }
        // cout << key << '\n';
        vector<int> res;
        int len = (int) adjacentPairs.size() + 1;
        set<int>    seen;
        int i = -1;
        while (++i < len)
        {
            seen.insert(key);
            res.push_back(key);
            for (int n: D[key])
            {
                idg[n]--;
                if (!seen.contains(n) && idg[n] < 2)
                {
                    key = n;
                    break ;
                }
            }
        }
        return res;
    }
};
