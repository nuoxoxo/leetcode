class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int x, int y, int nc)
    {
        if (img[x][y] == nc)
            return img;

        deque<pair<int, int>>   dq;
        int     c = img[0].size();
        int     r = img.size();
        int     oc = img[x][y];

        dq.push_back({x, y});
        while (!empty(dq))
        {
            int L = dq.front().first;
            int R = dq.front().second;

            dq.pop_front();
            img[L][R] = nc;
            if (L + 1 < r && img[L + 1][R] == oc)
                dq.push_back({L + 1, R});
            if (L - 1 > -1 && img[L - 1][R] == oc)
                dq.push_back({L - 1, R});
            if (R + 1 < c && img[L][R + 1] == oc)
                dq.push_back({L, R + 1});
            if (R - 1 > -1 && img[L][R - 1] == oc)
                dq.push_back({L, R - 1});
        }
        return img;
    }
};
