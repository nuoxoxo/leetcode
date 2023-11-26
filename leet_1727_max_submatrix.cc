class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix)
    {
        int R = matrix.size();
        int C = matrix[0].size();
        int r = 0, c;
        while (++r < R)
        {
            c = -1;
            while (++c < C)
            {
                // get longest streak of H
                if (matrix[r - 1][c] && matrix[r][c])
                    matrix[r][c] += matrix[r - 1][c];
            }
        }
        int res = 0;
        for (vector<int> & row: matrix)
        {
            sort(row.begin(), row.end());
            // sort(row.begin(), row.end(), greater<>{});
            c = -1;
            while (++c < C)
            {
                int H = row[c];
                int W = C - c;//c + 1;
                res = max(res, H * W);
            }
        }
        return res;
    }
};
