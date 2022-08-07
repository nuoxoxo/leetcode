class Solution {
public:
    int longestValidParentheses(string s)
    {
        int len = s.length();
        int c = 0, o = 0;
        int res = 0, i;

        i = -1;
        while (++i < len)
        {
            if (s[i] == '(')
                ++o;
            else
                ++c;
            if (o < c)
                o = c = 0;
            else if (o == c)
                res = max(res, o + c);
        }
        i = len;
        o = c = 0;
        while (--i > -1)
        {
            if (s[i] == '(')
                ++o;
            else
                ++c;
            if (o > c)
                o = c = 0;
            else if (o == c)
                res = max(res, o + c);
        }
        return res;
    }
};
