class Solution {
public:

    int     u = 0, outset = 1;  //  Global
    void dfs_backtrack(int x, int y, int walked, vector<vector<int>> &grid)
    {
        if (x >= grid.size() || y >= grid[0].size() ||
            x < 0 || y < 0 || grid[x][y] == -1)
            return ;
        if (grid[x][y] == 2)
        {
            if ( walked == outset ) ++u;
            return ;
        }
        grid[x][y] = -1;
        dfs_backtrack(x + 1, y, walked + 1, grid);
        dfs_backtrack(x - 1, y, walked + 1, grid);
        dfs_backtrack(x, y + 1, walked + 1, grid);
        dfs_backtrack(x, y - 1, walked + 1, grid);
        grid[x][y] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid)
    {
        int     x, y, i, j;

        i = -1;
        while (++i < grid.size())
        {
            j = -1;
            while (++j < grid[0].size())
            {
                if ( grid[i][j] == 1 )  x = i, y = j;
                if ( grid[i][j] == 0 )  outset++;
            }
        }
        dfs_backtrack(x, y, 0, grid);

        return (u);
    }

};
