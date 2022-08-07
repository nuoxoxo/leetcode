class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<int> p1(n, 0);
        vector<int> p2(n, 0);
        int         i;

        i = -1;
        while (++i < trust.size())
        {
            ++ p1[ trust[i][0] - 1 ] ;
            ++ p2[ trust[i][1] - 1 ] ;
        }
        i = -1;
        while (++i < n)
        {
            if (!p1[i] && p2[i] == n - 1)
                return (i + 1);
        }
        return (-1);
    }
};
