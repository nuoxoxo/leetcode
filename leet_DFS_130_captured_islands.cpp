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

    void    dfs_mark_illegal_paths(int x, int y, vector<vector<char>> &board)
    {
        if (x >= board.size() || y >= board[0].size() ||
            x < 0 || y < 0 || board[x][y] != 'O')
            return ;
        board[x][y] = 32;
        dfs_mark_illegal_paths(x + 1, y, board);
        dfs_mark_illegal_paths(x - 1, y, board);
        dfs_mark_illegal_paths(x, y + 1, board);
        dfs_mark_illegal_paths(x, y - 1, board);
    }

    void    solve(vector<vector<char>>& board)
    {
        int     m, n, i, j;

        m = board[0].size();
        n = board.size();
        i = -1;
        while (++i < m)
        {
            if (board[n - 1][i] == 'O')
                dfs_mark_illegal_paths(n - 1, i, board);
            if (board[0][i] == 'O')
                dfs_mark_illegal_paths(0, i, board);
        }
        i = -1;
        while (++i < n)
        {
            if (board[i][m - 1] == 'O')
                dfs_mark_illegal_paths(i, m - 1, board);
            if (board[i][0] == 'O')
                dfs_mark_illegal_paths(i, 0, board);
        }
        i = -1;
        while (++i < n)
        {
            j = -1;
            while (++j < m)
            {
                if (i && i < n - 1 && j && j < m - 1 && board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 32)
                    board[i][j] = 'O';
            }
        }
    }
};
