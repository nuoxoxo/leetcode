class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid)
    {

        int R = grid.size();
        int C = grid[0].size();

        std::function<int(int, int, int)> backtrack = [&](int r, int c, int curr) {
            if (r < 0 || r > R - 1 || c < 0 || c > C - 1 || grid[r][c] < 1)
                return curr;
            int temp = grid[r][c];
            grid[r][c] = 0;
            curr += temp;
            int res = max(
                max(backtrack(r - 1, c, curr), backtrack(r + 1, c, curr)),
                max(backtrack(r, c - 1, curr), backtrack(r, c + 1, curr))
            );
            grid[r][c] = temp;
            return res;
        };

        int r = -1, c;
        int res = 0;
        while (++r < R)
        {
            c = -1;
            while (++c < C)
            {
                if (grid[r][c] < 1)
                    continue ;
                res = max(res, backtrack(r, c, 0));
            }
        }
  
        return res;
    }
};
