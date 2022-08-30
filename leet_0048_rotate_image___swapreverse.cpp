class Solution {
public:
    void rotate(vector<vector<int>>& g)
    {
        int     i, j, n;

        n = g.size();
        i = -1;
        while (++i < n)
        {
            j = i;
            while (++j < n)
            {
                swap(g[i][j], g[j][i]);
            }
            reverse(g[i].begin(), g[i].end());
        }
    }
};
