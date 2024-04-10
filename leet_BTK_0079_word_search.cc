class Solution {
public:

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    bool exist(vector<vector<char>>& board, string word)
    {
        int R = (int) board.size(), C = (int) board[0].size();
        vector<vector<bool>> seen(R, vector<bool>(C, false));
        int r = -1, c, i;
        while (++r < R)
        {
            c = -1;
            while (++c < C)
            {
                i = -1;
                if (dfs(board, r, c, word, 0, seen))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& g, int r, int c, string &s, int idx, vector<vector<bool>> & seen)
    {
        int N = s.length();
        if (idx > N - 1)
            return true;
        int R = (int) g.size(), C = (int) g[0].size();
        if (r < 0 || r > R - 1 || c < 0 || c > C - 1 || g[r][c] != s[idx] || seen[r][c])
            return false;
        seen[r][c] = true;
        int i = -1;
        while (++i < 4)
        {
            int rr = r + dr[i], cc = c + dc[i];
            if (dfs(g, rr, cc, s, idx + 1, seen))
                return true;
        }
        seen[r][c] = false;
        return false;
    }

};
