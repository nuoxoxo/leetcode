class Solution {
public:
    int numIslands(vector<vector<char>>& g)
    {
        if (g.empty())
            return 0;

        int d[4][2] = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        int r = g.size(), c = g[0].size(), res = 0, i, j, x, y, k;
        vector<vector<bool>>    visited(r, vector<bool>(c, false));
        deque<vector<int>>      dq;

        i = -1;
        while (++i < r)
        {
            j = -1;
            while (++j < c)
            {
                if (g[i][j] == '1' && ! visited[i][j])
                {
                    res++;
                    visited[i][j] = true;
                    dq.push_back({i, j});
                    while (! dq.empty())
                    {
                        k = -1;
                        while (++k < 4)
                        {
                            x = dq.front()[0] + d[k][0];
                            y = dq.front()[1] + d[k][1];
                            if (x < r && x > -1 && y < c && y > -1
                                && g[x][y] == '1' && ! visited[x][y])
                            {
                                dq.push_back({x, y});
                                visited[x][y] = true;
                            }
                        }
                        dq.pop_front();
                    }
                }
            }
        }
        return res;
    }
};
