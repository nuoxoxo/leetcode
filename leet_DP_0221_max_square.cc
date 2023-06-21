class Solution {
public:
    int maximalSquare(vector<vector<char>> & m) {
        if (!m.size())
            return 0;
        int R = (int) m.size();
        int C = (int) m[0].size();
        int a = 0;
        vector<vector<int>> DP(R + 1, vector<int>(C + 1, 0));
        int r = -1, c;
        while (++r < R)
        {
            c = -1;
            while (++c < C)
            {
                if (m[r][c] == '1')
                {
                    DP[r + 1][c + 1] = 1 + min({
                        DP[r][c], DP[r + 1][c], DP[r][c + 1]
                    });
                    a = max(a, DP[r + 1][c + 1]);
                }
            }
        }
        return a * a;
    }
};
