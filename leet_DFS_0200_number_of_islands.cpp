/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

class Solution {
#define vvc vector<vector<char>>
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int c = grid[0].size();
        int r = grid.size();
        int res = 0, i = -1, j;

        while (++i < r)
        {
            j = -1;
            while (++j < c)
            {
                if (grid[i][j] == '1')
                {
                    res ++ ;
                    dfs(grid,i,j,r,c);
                }
            }
        }
        return res ;
    }

    void    dfs(vvc& grid, int x, int y, int r, int c)
    {
        if (x > r - 1 || x < 0 || y > c - 1 || y < 0 || grid[x][y] != '1')
            return ;
        grid[x][y] = ' ' ;
        dfs(grid, x + 1, y, r, c);
        dfs(grid, x - 1, y, r, c);
        dfs(grid, x, y + 1, r, c);
        dfs(grid, x, y - 1, r, c);
    }
};
