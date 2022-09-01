class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n)
    {
        vector<vector<int>>     r(m, vector<int>(n, 0));
        int len = original.size();
        int i, x, y;
        
        if (len != m * n)
            return {};
        i = 0;
        x = -1;
        while (++x < m)
        {
            y = -1;
            while (++y < n)
                r[x][y] = original[i++];
        }
        return r;
    }
};
