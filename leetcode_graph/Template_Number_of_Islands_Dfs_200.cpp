class Solution {

#define vvc vector<vector<char>>

public:
    int numIslands(vector<vector<char>>& grid)
    {
        int     c = grid[0].size();
        int     r = grid.size();
        int     res = 0;
        int     i, j;

        i = -1;
        while (++i < r)
        {
            j = -1;
            while (++j < c)
            {
                if (grid[i][j] == '1')
                {
                    ++res;
                    dfs(grid, i, j, r, c);
                }
            }
        }
        return res ;
    }

    void    dfs(vvc & grid, int x, int y, int r, int c)
    {
        int     dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int     i = -1;
        int     newx, newy;

        if (x > r - 1 || x < 0 || y > c - 1 || y < 0 || grid[x][y] != '1')
            return ;
        grid[x][y] = ' ' ;
        while (++i < 4)
        {
            newx = x + dir[i][0];
            newy = y + dir[i][1];
            dfs(grid, newx, newy, r, c);
        }
    }

};
