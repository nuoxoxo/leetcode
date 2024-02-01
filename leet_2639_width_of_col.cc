class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int c = -1;
        int r;
        int R = grid.size(), C = grid[0].size();
        vector<int> res;
        while (++c < C)
        {
            vector<int> temp;
            r = -1;
            while (++r < R)
            {
                temp.push_back(grid[r][c]);
            }
            r = -1;
            int size = -1;
            while (++r < R)
            {
                int len = to_string(temp[r]).length();
                size = max(size, len);
            }
            res.push_back(size);
        }
        return res;
        
    }
};
