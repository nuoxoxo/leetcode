class Solution {

using   vvi = vector<vector<int>>;

public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int c = (int) grid[0].size();
        int r = (int) grid.size();
        int res = 0;
        int i = -1, j;
        while (++i < r)
        {
            j = -1;
            while (++j < c)
            {
                if (grid[i][j])
                    res += 4 - countNeighbors(i, j, grid);
            }
        }
        return res ;
    }

    int oneNeighbor(int x, int y, vvi& grid)
    {
        if (x < grid.size() && y < grid[0].size()
            && x > -1 && y > -1 && grid[x][y])
            return 1;
        return 0;
    }

    int countNeighbors(int x, int y, vvi& grid)
    {
        return oneNeighbor(x + 1, y, grid) + oneNeighbor(x - 1, y, grid)
            + oneNeighbor(x, y + 1, grid) + oneNeighbor(x, y - 1, grid);
    }
};
