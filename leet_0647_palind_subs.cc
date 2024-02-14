class Solution {
public:
    int countSubstrings(string s)
    {
        int len = s.length();

        if (!len || len == 1)
            return len;

        int i, L, R;
        int res = 0;

        i = -1;
        while (++i < len)   // odd
        {
            L = R = i;
            while (L > -1 && R < len)
            {
                if (s[L] == s[R])
                {
                    ++res;
                    --L;
                    ++R;
                }
                else
                    break;
            }
        }
        i = -1;
        while (++i < len)   /// even
        {
            L = i;
            R = i + 1;
            while (L > -1 && R < len)
            {
                if (s[L] == s[R])
                {
                    ++res;
                    --L;
                    ++R;
                }
                else
                    break;
            }
        }
        return res;
    }
};
