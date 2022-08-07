class Solution {
public:
    int minimumTotal(vector<vector<int>>& tg)
    {
        int i = (int) tg.size() - 1;
        while (--i > -1)
        {
            int j = -1;
            while (++j < (int) tg[i].size())
            {
                tg[i][j] += min(tg[i + 1][j], tg[i + 1][j + 1]);
            }
        }
        return tg[0][0];
    }
    
};
