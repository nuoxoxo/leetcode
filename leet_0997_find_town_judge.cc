class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<int> rr(n, 0), cc(n, 0);
        int         i;

        for (vector<int>& t: trust)
        {
            ++rr[t[0] - 1];
            ++cc[t[1] - 1];
        }
        i = -1;
        while (++i < n)
        {
            if (!rr[i] && cc[i] == n - 1)
                return i + 1;
        }
        return -1;
    }
};
