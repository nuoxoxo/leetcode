class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid)
    {
        int len = grid.size();
        int r = -1, c;
        while (++r < len)
        {
            c = -1;
            while (++c < len)
            {
                if ((r == c || c == len - r - 1) && ! grid[r][c])
                    return false;
                else if (r ^ c && c ^ len - r - 1 && grid[r][c])
                    return false;
            }
        }
        return true;
    }
};
