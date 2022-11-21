class Solution {
public:
    int numIslands(vector<vector<char>>& g)
    {

        int     C = g[0].size();
        int     R = g.size();
        int     res = 0;
        int     i, j;
        
        if ( !R || !C)
            return (res);
        i = -1;
        while (++i < R)
        {
            j = -1;
            while (++j < C)
            {
                if (g[i][j] == '1')
                {
                    res += 1;
                    BFS(g, i, j, R, C);
                }
            }
        }
        return res;
    }

    void    BFS(vector<vector<char>> & g, int i, int j, int R, int C)
    {
        vector<vector<int>>     dir = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        deque<vector<int>>      dq  = { {i, j} };

        int     x, y, temp_x, temp_y;

        g[i][j] = '0';
        while (!dq.empty())
        {
            temp_x = dq.front()[0];
            temp_y = dq.front()[1];
            dq.pop_front();
            for (vector<int> d: dir)
            {
                x = temp_x + d[0];
                y = temp_y + d[1];
                if (x < R && x > -1 && y < C && y > -1 && g[x][y] == '1')
                {
                    dq.push_back( {x, y} );
                    g[x][y] = '0';
                }
            }
        }
    }
};
