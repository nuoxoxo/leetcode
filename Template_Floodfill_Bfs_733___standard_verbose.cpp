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

        deque<pair<int, int>>   dq;

        dq.push_back({x, y});
        while (!empty(dq))
        {
            i = dq.front().first;
            j = dq.front().second;
            img[i][j] = nc;
            dq.pop_front();
            if (i + 1 < r && img[i + 1][j] == oc)
            {
                dq.push_back( {i + 1, j} );
            }
            if (i - 1 > -1 && img[i - 1][j] == oc)
            {
                dq.push_back( {i - 1, j} );
            }
            if (j + 1 < c && img[i][j + 1] == oc)
            {
                dq.push_back( {i, j + 1} );
            }
            if (j - 1 > -1 && img[i][j - 1] == oc)
            {
                dq.push_back( {i, j - 1} );
            }
        }
        return img;
    }
};
