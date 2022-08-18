class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        unordered_map<int, int>             mp;
        vector<int>                         vi;
        int                                 i, n, res, count;

        for (int n : arr)
            mp[n]++;
        transform(mp.begin(), mp.end(), back_inserter(vi), [](pair<int, int> const& pair) {
            return pair.second;
        });
        sort(vi.begin(), vi.end());
        n = arr.size();
        i = vi.size();
        res = 0;
        count = n;
        while (--i > -1 && count > n / 2)
        {
            count -= vi[i];
            res++;
        }
        return res;
    }
};
