class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        
        int c = grid[0].size();
        int r = grid.size();

        k %= c * r;
        if (!k)
            return grid;

        vector<vector<int>> v(r, vector<int>(c, 0));
        int i = -1, j;

        while (++i < r)
        {
            j = -1;
            while (++j < c)
            {
                int pos = (i * c + j + k) % (r * c); // pos IS index in a 1-d array 
                int di = pos / c;
                int dj = pos % c;
                v[di][dj] = grid[i][j];
            }
        }
        return v;
    }
};
