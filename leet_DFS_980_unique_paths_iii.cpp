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
public:

    int dfs_backtrack(int x, int y, int walked, int outset, vector<vector<int>> &grid)
    {
        int     u = 0;

        if (x >= grid.size() || y >= grid[0].size() ||
            x < 0 || y < 0 || grid[x][y] == -1)
            return (0);
        if (grid[x][y] == 2)
        {
            if ( walked == outset )
                return (++u);
            return (0);
        }
        grid[x][y] = -1;    //  treat cells been as obstacles
        u += dfs_backtrack(x + 1, y, walked + 1, outset, grid);
        u += dfs_backtrack(x - 1, y, walked + 1, outset, grid);
        u += dfs_backtrack(x, y + 1, walked + 1, outset, grid);
        u += dfs_backtrack(x, y - 1, walked + 1, outset, grid);
        grid[x][y] = 0;     //  backtracking    

        return (u);
    }

    int uniquePathsIII(vector<vector<int>>& grid)
    {
        int     x, y, i, j;
        int     outset = 1;    // all initial empty cells (+) 1 starting point

        i = -1;
        while (++i < grid.size())
        {
            j = -1;
            while (++j < grid[0].size())
            {
                if ( grid[i][j] == 1 )
                    x = i, y = j;
                if ( grid[i][j] == 0 )
                    outset++;
            }
        }

        return ( dfs_backtrack(x, y, 0, outset, grid) );
    }

};
