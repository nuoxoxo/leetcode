class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        int                     i, j, n = envelopes.size();
        vector<pair<int, int>>  v(n);
        vector<int>             res(n, 1);

        i = -1;
        while (++i < n)
        {
            v[i].first = envelopes[i][0];
            v[i].second = envelopes[i][1];
        }
        sort(v.begin(), v.end());
        i = 0;
        while (++i < n)
        {
            j = -1;
            while (++j < i)
            {
                if (v[i].first > v[j].first && v[i].second > v[j].second)
                    res[i] = max(res[i], res[j] + 1);
            }
        }
        return *max_element(res.begin(), res.end());
    }
};
