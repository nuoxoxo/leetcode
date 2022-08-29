class Solution {
public:
    int numIslands(vector<vector<char>>& g)
    {
        int res, r, c, i, j;

        r = g.size();
        c = g[0].size();
        if (!r || !c)
            return 0;
        res = 0;
        i = -1;
        while (++i < r)
        {
            j = -1;
            while (++j < c)
            {
                if (g[i][j] == '1')
                {
                    res += 1;
                    BFS(g, i, j, r, c);
                }
            }
        }
        return res;
    }

    void    BFS(vector<vector<char>> & g, int i, int j, int r, int c)
    {
        int     x, y;

        deque<vector<int>>  dq;
        dq.push_back({i, j});
        g[i][j] = '0';
        while (!dq.empty())
        {
            x = dq.front()[0];
            y = dq.front()[1];
            dq.pop_front();
            if (x < r - 1 && g[x + 1][y] == '1')
            {
                dq.push_back({x + 1, y});
                g[x + 1][y] = '0';
            }
            if (x > 0 && g[x - 1][y] == '1')
            {
                dq.push_back({x - 1, y});
                g[x - 1][y] = '0';
            }
            if (y < c - 1 && g[x][y + 1] == '1')
            {
                dq.push_back({x, y + 1});
                g[x][y + 1] = '0';
            }
            if (y > 0 && g[x][y - 1] == '1')
            {
                dq.push_back({x, y - 1});
                g[x][y - 1] = '0';
            }
        }
    }
};







