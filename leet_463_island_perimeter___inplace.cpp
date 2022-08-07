class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        vector<int> dx = {1, 0, 0, -1};
        vector<int> dy = {0, -1, 1, 0};
        int c = (int) grid[0].size(), r = (int) grid.size();
        int tt = 0, x = -1, y;
        while (++x < r)
        {
            y = -1;
            while (++y < c)
            {
                if (grid[x][y])
                {
                    int n = -1;
                    while (++n < 4)
                    {
                        int i = x + dx[n], j = y + dy[n];
                        if (i == -1 || i == r || j == -1 || j == c || !grid[i][j])
                            ++tt;
                    }
                }
            }
        }
        return tt ;
    }
};
