class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& g, int k)
    {
        int n = g.size();
        vector<pair<int, int>>  v ;
        vector<int>             res;
        int i = -1;

        while (++ i < n)
        {
            int temp = accumulate(g[i].begin(), g[i].end(), 0) ;
            v.push_back((make_pair(i, temp)));
        }
        sort(v.begin(), v.end(), paircmp);
        i = -1;
        while (++ i < k)
            res.push_back(v[i].first);
        return (res) ;
    }
    
    static bool paircmp(pair<int,int> x, pair<int,int> y)
    {
        if (x.second == y.second)
            return (x.first < y.first);
        return (x.second < y.second);
    }
};
