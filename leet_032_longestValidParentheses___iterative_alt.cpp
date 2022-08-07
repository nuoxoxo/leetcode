class Solution {
public:
    int longestValidParentheses(string s)
    {
        int res = 0, o = 0, c = 0;

        for (char ch: s)
        {
            if (ch == '(')
                ++o;
            else
                ++c;
            if (o < c)
                o = c = 0;
            else if (o == c)
                res = max(res, o + c);
        }
        reverse(s.begin(), s.end());
        o = c = 0;
        for (char ch: s)
        {
            if (ch == '(')
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
