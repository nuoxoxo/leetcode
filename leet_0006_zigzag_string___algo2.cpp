class Solution {
public:
    string convert(string s, int numRows)
    {
        string          res;
        int             n, r, c, i, in_between;

        if (numRows < 2)
            return s;
        n = s.length();
        i = -1;
        while (++i < numRows)
        {
            r = 2 * (numRows - 1);
            c = i;
            while (c < n)
            {
                res += s[c];
                in_between = r + c - i * 2;
                if (i < numRows - 1 && i > 0 && in_between < n)
                    res += s[in_between];
                c += r;
            }
        }
        return res;
    }
};
