class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid)
    {
        int rows = (int) grid.size();
        int cols = (int) grid[0].size();
        int r, c;
        vector<int> r1, r0, c0(cols, 0), c1(cols, 0);
        vector<vector<int>> res(rows, vector<int>(cols, 0));

        for (vector<int> row : grid)
        {
            r1.push_back(count(row.begin(), row.end(), 1));
            r0.push_back(count(row.begin(), row.end(), 0));
            r = -1;
            while (++r < cols)
            {
                if (!row[r])
                    ++c0[r];
                else
                    ++c1[r];
            }
        }
        r = -1;
        while (++r < rows)
        {
            c = -1;
            while (++c < cols)
                res[r][c] = r1[r] - r0[r] + c1[c] - c0[c];
        }
        return res;
    }
};
