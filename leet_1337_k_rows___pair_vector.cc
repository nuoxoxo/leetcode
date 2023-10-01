class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        vector<int> res ;
        vector<pair<int, int>>  v;
        int len = (int) mat.size();
        int i;

        i = -1;
        while (++i < len)
        {
            int temp = 0;
            for (int n: mat[i])
                temp += n;
            v.push_back({temp, i});
        }
        sort(v.begin(), v.end(), [](pair<int, int> x, pair<int, int> y){
            if (x.first ^ y.first)
                return x.first < y.first;
            return x.second < y.second;
        });
        i = -1;
        while (++i < k)
            res.push_back(v[i].second);
        return res;
    }
};
