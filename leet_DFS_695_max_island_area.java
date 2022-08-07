class Solution {
    public int maxAreaOfIsland(int[][] grid)
    {
        int	res;
        int r;
        int c;
        int	i;
        int	j;
        int	temp;

        i = -1;
        res = 0;
        r = grid.length;
        c = grid[0].length;
        while (++i < r)
        {
            j = -1;
            while (++j < c)
            {
                temp = dfs(grid, i, j);
                res = res > temp ? res : temp;
            }
        }
        return (res);
    }

    public int	dfs(int[][] g, int i, int j)
    {
        int	l;
        int	u;
        int	d;
        int	r;

        if (i < 0 || j < 0 || i > g.length - 1 || j > g[0].length - 1 || g[i][j] != 1)
            return (0);
        g[i][j] = 0;
        l = dfs(g, i - 1, j);
        u = dfs(g, i, j - 1);
        d = dfs(g, i, j + 1);
        r = dfs(g, i + 1, j);
        return (l + u + d + r + 1);
    }
}
