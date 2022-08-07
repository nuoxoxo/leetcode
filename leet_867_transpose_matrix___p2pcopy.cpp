class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& m)
    {
        int r = m.size();
        int c = m[0].size();
        vector<vector<int>> res(c, vector<int>(r, 0));
        int i = -1, k = 0;
        while (++i < c)
        {
            int j = -1;
            while (++j < r)
                res[k][j] = m[j][i];
            ++k;
        }
        return res;
    }
};
