class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int color)
    {
        if (image[x][y] == color)
            return (image);

        int     C = image[0].size();
        int     R = image.size();
        int     old_color = image[x][y];
        int     temp_x, temp_y, res;

        vector<vector<int>>     dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        deque<vector<int>>      dq = {{x, y}};  

        res = 0;
        while ( !dq.empty())
        {
            temp_x = dq.front()[0];
            temp_y = dq.front()[1];
            image[temp_x][temp_y] = color;
            dq.pop_front();
            for (vector<int> d : dir)
            {
                x = temp_x + d[0];
                y = temp_y + d[1];
                if (x < R && x > -1 && y < C && y > -1 && image[x][y] == old_color)
                {
                    dq.push_back({x, y});
                }
            }
        }
        return (image);
    }
};
