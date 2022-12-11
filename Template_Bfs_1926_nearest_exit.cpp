class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        int     C = (int) maze[0].size();
        int     R = (int) maze.size();
        int     i, n, x, y, x_temp, y_temp;
        // int     res = 0;
        int     res = 1;

        vector<vector<int>>     dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        deque<pair<int, int>>   D;

        D.push_back( {entrance[0], entrance[1]} );
        maze[entrance[0]][entrance[1]] = '+';
        while (!D.empty())
        {
            n = (int) D.size();
            while (n)
            {
                x_temp = D.front().first;
                y_temp = D.front().second;
                D.pop_front();
                i = -1;
                while (++i < 4)
                {
                    x = dir[i][0] + x_temp;
                    y = dir[i][1] + y_temp;
                    if (x < R && x > -1 && y < C && y > -1 && maze[x][y] == '.')
                    {
                        if (!x || !y || x == R - 1 || y == C - 1)
                            return (res) ;
                        else
                        {
                            maze[x][y] = '+';
                            D.push_back( {x, y} );
                        }
                    }
                }
                --n;
            }
            ++res;
        }
        return (-1) ;
    }
};
