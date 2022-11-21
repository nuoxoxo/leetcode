class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int x, int y, int nc)
    {
        if (img[x][y] == nc)
            return img;

        int     oc = img[x][y];
        int     c = img[0].size();
        int     r = img.size();
        int     i, j;

        vector<vector<int>>     dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

        deque<pair<int, int>>   dq;
        dq.push_back({x, y});

        while (!empty(dq))
        {
            i = dq.front().first;
            j = dq.front().second;
            img[i][j] = nc;
            dq.pop_front();
            for (vector<int> d: dir)
            {
                x = i + d[0];
                y = j + d[1];
                if (x < r && x > -1 && y < c && y > -1 && img[x][y] == oc)
                    dq.push_back({x, y});
            }
        }
        return img;
    }
};
