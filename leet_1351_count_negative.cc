class Solution {
public:
    int countNegatives(vector<vector<int>>& g)
    {
        int res = 0;
        int R = (int) g.size();
        int C = (int) g[0].size();
        int r = 0;
        int c = C - 1;
        while (r < R && c > -1)
        {
            if (g[r][c] < 0)
            {
                res += R - r;
                --c;
            }
            else
            {
                ++r;
            }
        }
        return res ;
    }

    /*
    [
        [ 4, 3, 2,-1],
        [ 3, 2, 1,-1],
        [ 1, 1,-1,-2],
        [-1,-1,-2,-3]
    ]
    */
};
