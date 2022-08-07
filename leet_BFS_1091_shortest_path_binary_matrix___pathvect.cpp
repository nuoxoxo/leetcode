class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int         n = (int) grid.size();

        if (n < 2)
            return 1;
        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;

        vector<int>             dx = {-1,-1,-1, 0,0, 1,1,1};
        vector<int>             dy = {-1, 0, 1,-1,1,-1,0,1};
        deque<pair<int, int>>   dq;
        int                     res;

        res = 0;
        grid[0][0] = 1;
        dq.push_back(make_pair(0, 0));
        while (true)
        {
            int todo = dq.size();

            if (!todo)
                break;
            ++res;
            while (todo--)
            {
                pair<int, int>  p = dq.front();
                int             x = p.first;
                int             y = p.second;
                int             i = -1;

                if (x == n - 1 && y == n - 1)
                    return res;
                dq.pop_front();
                while (++i < 8)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx > -1 && ny > -1 && nx < n && ny < n && !grid[nx][ny])
                    {
                        dq.push_back(make_pair(nx, ny));
                        grid[nx][ny] = 1;
                    }
                }
            }
        }
        return -1 ;
    }
};
