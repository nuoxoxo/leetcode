class Solution {
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        vector<int(*)(string, string, int)> Solutions {
            Sliding_window,
        };
        return Solutions[0](s, t, maxCost);
    }

    static int Sliding_window(string s, string t, int maxCost)
    {
        int L = 0;
        int R = -1;
        int res = 0;
        int N = s.length();
        int windowcost = 0;
        while (++R < N)
        {
            windowcost += abs(s[R] - t[R]);
            while (windowcost > maxCost)
            {
                windowcost -= abs(s[L] - t[L]);
                ++L;
            }
            res = max(res, R - L + 1);
        }
        return res;
    }
};
