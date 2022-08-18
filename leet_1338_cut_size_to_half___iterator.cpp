class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        unordered_map<int, int>             mp;
        unordered_map<int, int>::iterator   it;
        vector<int>                         vi;
        int                                 i, n, res, count;

        for (int n : arr)
            mp[n]++;
        it = mp.begin();
        while (it != mp.end())
        {
            vi.push_back(it->second);
            it++;
        }
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
