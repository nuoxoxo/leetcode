class Solution {
public:
    int maxPower(string s)
    {
        int     p, i, len, temp;

        len = s.length();
        if (!len)       return (0);
        if (len == 1)   return (1);
        p = temp = 1;
        i = 0;
        while (++i < s.length())
        {
            if (s[i] == s[ i - 1 ]) temp++;
            else
            {
                p = p > temp ? p : temp;
                temp = 1;
            }
        }

        return (p > temp ? p : temp);
    }
};
