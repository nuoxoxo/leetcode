class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g)
    {
        int                     c = g[0].size();
        int                     r = g.size();
        vector<vector<int>>     g2(r, vector<int>(c, 0));
        vector<vector<int>>     d = {{1, 0}, {0, 1}};
        deque<pair<int, int>>   dq;

        if (!g[0][0])
            g2[0][0] = 1;
        else
            g2[0][0] = 0;
        dq.push_back(make_pair(0, 0));
        while (!dq.empty())
        {
            int i = dq.front().first;
            int j = dq.front().second;
            int val = g2[i][j];

            dq.pop_front();
            for (vector<int> p: d)
            {
                int di = i + p[0];
                int dj = j + p[1];
                if (di == r || dj == c || g[di][dj] == 1)
                    continue;
                if (g2[di][dj] == 0)
                    dq.push_back(make_pair(di, dj));
                g2[di][dj] += val;
            }
        }
        return g2[r - 1][c - 1];
    }
};
