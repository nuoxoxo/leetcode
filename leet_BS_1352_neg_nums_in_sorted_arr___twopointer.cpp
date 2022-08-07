class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int res = 0;
        int r = grid.size();
        int c = grid[0].size();
        int i = 0;
        int j = c - 1;
        while (i < r && j > -1)
        {
            if (grid[i][j] < 0)
            {
                res += r - i;
                --j;
            }
            else
                ++i;
        }
        return res;
    }
};
