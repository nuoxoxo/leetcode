class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n)
    {
        int N = original.size();
        if (m * n ^ N)
            return {};
        vector<vector<int>> res(m, vector<int>(n, 0));
        int i = -1, r = -1, c;
        while (++r < m)
        {
            c = -1;
            while (++c < n)
                res[r][c] = original[++i];
        }
        return res;
    }
};
