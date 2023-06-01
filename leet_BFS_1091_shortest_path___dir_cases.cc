class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = (int) grid.size();

        if (n < 2)
            return 1;
        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;

        deque<pair<int, int>>   dq;
        int                     res;

        res = 1;
        grid[0][0] = 1;
        dq.push_back(make_pair(0, 0));
        while (true)
        {
            int todo = dq.size();

            if (!todo)
                break;
            while (todo--)
            {
                pair<int, int>  p = dq.front();
                int             i = p.first;
                int             j = p.second;

                if (i == n - 1 && j == n - 1)
                    return res;
                dq.pop_front();
                if (i && j && !grid[i - 1][j - 1])
                {
                    dq.push_back(make_pair(i - 1, j - 1));  // LU
                    grid[i - 1][j - 1] = 1;
                }
                if (i && !grid[i - 1][j])
                {
                    dq.push_back(make_pair(i - 1, j));  // U
                    grid[i - 1][j] = 1;
                }
                if (i && j + 1 < n && !grid[i - 1][j + 1])
                {
                    dq.push_back(make_pair(i - 1, j + 1));  // RU
                    grid[i - 1][j + 1] = 1;
                }
                if (j && !grid[i][j - 1])
                {
                    dq.push_back(make_pair(i, j - 1));  // L
                    grid[i][j - 1] = 1;
                }
                if (j + 1 < n && !grid[i][j + 1])
                {
                    dq.push_back(make_pair(i, j + 1));  // R
                    grid[i][j + 1] = 1;
                }
                if (i + 1 < n && j && !grid[i + 1][j - 1])
                {
                    dq.push_back(make_pair(i + 1, j - 1));  // LD
                    grid[i + 1][j - 1] = 1;
                }
                if (i + 1 < n && !grid[i + 1][j])
                {
                    dq.push_back(make_pair(i + 1, j));  // D
                    grid[i + 1][j] = 1;
                }
                if (i + 1 < n && j + 1 < n && !grid[i + 1][j + 1])
                {
                    dq.push_back(make_pair(i + 1, j + 1));  // RD
                    grid[i + 1][j + 1] = 1;
                }
            }
            ++res;
        }
        return -1 ;
    }
};
