class Solution {
public:
    int numIslands(vector<vector<char>>& g)
    {
        int     C = (int) g[0].size();
        int     R = (int) g.size();
        int     dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int     res = 0;
        int     it, i, j, x, y, temp_x, temp_y;

        deque<vector<int>>  dq;

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
                    ++res;
                    dq.push_back( {i, j} );
                    while (!dq.empty())
                    {
                        temp_x = dq.front()[0];
                        temp_y = dq.front()[1];
                        it = -1;
                        while (++it < 4)
                        {
                            x = temp_x + dir[it][0];
                            y = temp_y + dir[it][1];
                            if (x < R && x > -1 && y < C && y > -1 && g[x][y] == '1')
                            {
                                dq.push_back( {x, y} );
                                g[x][y] = '0';
                            }
                        }
                        dq.pop_front();
                    }
                }
            }
        }
        return (res);
    }
};


