class Solution {
public:
    int uniquePaths(int r, int c)
    {
        deque<pair<int, int>>   dq;
        vector<vector<int>>     g(r, vector<int>(c, 1));
        int                     i, j;

        dq.push_back(make_pair(0, 0));
        while (!dq.empty())
        {
            i = dq.front().first;
            j = dq.front().second;
            dq.pop_front();
            // cout << i << ' ' << j << endl;
            if (i == r || j == c || g[i][j] > 1)
                continue;
            if (i > 0 && j > 0)
                g[i][j] = g[i - 1][j] + g[i][j - 1];
            dq.push_back(make_pair(i + 1, j));
            dq.push_back(make_pair(i, j + 1));
        }
        return g[r - 1][c - 1];
    }

    
};
