class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& G/*grid*/)
    {
        int R = G.size(), C = G[0].size();
        int r = -1, c;
        while (++r < R)
        {
            c = -1;
            while (++c < C)
            {
                if ((r < R - 1 && G[r][c] != G[r + 1][c])
                || (c < C - 1 && G[r][c] == G[r][c + 1]))
                    return false;
            }
        }
        return true;
    }
};
