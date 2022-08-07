class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int     temp;
        int     res;
        int     r;
        int     c;
        int     i;
        int     j;

        c = grid[0].size();
        r = grid.size();
        res = 0;
        i = -1;
        while (++i < r)
        {
            j = -1;
            while (++j < c)
            {
                if (grid[i][j])
                {
                    temp = 0;
                    bfs(grid, i, j, temp);
                    res = res > temp ? res : temp;
                }
            }
        }
        return (res);
    }

    void    bfs(vector<vector<int>>& grid, int i, int j, int& temp)
    {
        deque<pair<int, int>>   dq;
        vector<int>             dx = {-1, 0, 1, 0};
        vector<int>             dy = {0, -1, 0, 1};
        int                     k, x, y;

        dq.push_back({i, j});
        while (!dq.empty())
        {
            ++temp;
            x = dq.front().first;
            y = dq.front().second;
            grid[x][y] = 0;
            dq.pop_front();
            k = -1;
            while (++k < 4)
            {
                i = x + dx[k];
                j = y + dy[k];
                if (valid(i, j, grid.size(), grid[0].size()) && grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    dq.push_back({i, j});
                }
            }
        }
    }

    bool    valid(int x, int y, int r, int c)
    {
        if (x < 0 || x > r - 1 || y < 0 || y > c - 1)
            return (false);
        return (true);
    }
};
