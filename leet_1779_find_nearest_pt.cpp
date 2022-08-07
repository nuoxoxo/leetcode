class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points)
    {
        int idx, res, dif, i;
        idx = res = 1e6;
        i = -1;
        while (++i < (int) points.size())
        {
            if (x == points[i][0])
            {
                dif = abs(y - points[i][1]);
                if (dif < res)
                    res = dif, idx = i;
                if (!res)
                    return i;
            }
            if (y == points[i][1])
            {
                dif = abs(x - points[i][0]);
                if (dif < res)
                    res = dif, idx = i;
                if (!res)
                    return i;
            }
        }
        return idx ^ (int) 1e6 ? idx : -1 ;
    }
};
