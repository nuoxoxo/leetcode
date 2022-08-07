class Solution {
public:
    string longestPalindrome(string s)
    {
        int from = 0, to = 1, i = 0;
        int len = s.length();
        int L, R, dist;

        while (++i < len)
        {
            L = i - 1;
            R = i;
            while (R < len && L > -1 && s[L] == s[R])
            {
                dist = R - L + 1;
                if (dist > to)
                {
                    to = dist;
                    from = L;
                }
                --L;
                ++R;
            }
            L = i - 1;
            R = i + 1;
            while (R < len && L > -1 && s[L] == s[R])
            {
                dist = R - L + 1;
                if (dist > to)
                {
                    to = dist;
                    from = L;
                }
                --L;
                ++R;
            }
        }
        return s.substr(from, to);
    }
};
