class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k)
    {
        vector<int>     g;
        int             side, i, j;

        i = -1;
        side = (int) m.size();
        while (++i < side)
        {
            j = -1;
            while (++j < side)
                g.push_back(m[i][j]);
        }
        sort(g.begin(), g.end());
        return g[k - 1];
    }
};
