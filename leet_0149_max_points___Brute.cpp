class Solution {
public:
    int maxPoints(vector<vector<int>>& pt)
    {
        int len = pt.size();
        if (len < 3)
            return len;
        int res = 2;
        int i, j, k;
        i = -1;
        while (++i < len)
        {
            j = i;
            while (++j < len)
            {
                int temp = 2;
                k = -1;
                while (++k < len)
                {
                    if (k == i || k == j)
                        continue ;
                    if ((pt[j][1] - pt[i][1]) * (pt[i][0] - pt[k][0]) == 
                        (pt[i][1] - pt[k][1]) * (pt[j][0] - pt[i][0]))
                        temp++;
                }
                res = max(temp, res);
            }
        }
        return res;
    }
};
