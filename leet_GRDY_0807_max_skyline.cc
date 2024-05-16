class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
    {
        int N = grid.size();
        assert(N == grid.size());
        vector<int> R(N, 0);
        vector<int> C(N, 0);
        int r, c;

        r = -1;
        while (++r < N)
        {
            c = -1;
            while (++c < N)
            {
                int val = grid[r][c];
                R[r] = max(R[r], val);
                C[c] = max(C[c], val);
            }
        }
        int res = 0;
        r = -1;
        while (++r < N)
        {
            c = -1;
            while (++c < N)
            {
                int max_tolerance = min(R[r], C[c]);
                if (max_tolerance - grid[r][c] > 0)
                    res += max_tolerance - grid[r][c];
            }
        }
        return res;
    }
};
