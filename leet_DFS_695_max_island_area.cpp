class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int r, c, x, y, tmp, res;

        c = grid[0].size();
        r = grid.size();
        res = 0;
        x = -1;
        while (++x < r)
        {
            y = -1;
            while (++y < c)
            {
                if (grid[x][y] == 1)
                {
                    tmp = dfs(grid, x, y);
                    res = max(res, tmp);
                }
            }
        }
        return res ;
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y)
    {
        int     l;
        int     r;
        int     u;
        int     d;

        if (x < 0 || y < 0 || x > grid.size() - 1 || y > grid[0].size() - 1 || grid[x][y] ^ 1)
            return (0);
        grid[x][y] = 0;
        l = dfs(grid, x - 1, y);
        r = dfs(grid, x + 1, y);
        u = dfs(grid, x, y - 1);
        d = dfs(grid, x, y + 1);
        return (1 + l + r + u + d);
    }
};
