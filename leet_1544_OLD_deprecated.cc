class Solution {
public:
    string makeGood(string s)
    {
        int     i, j;

        i = -1;
        j = -1;
        while (++i < s.length())
        {
            if (j == -1 || abs(s[i] - s[j]) != 32)
                s[++j] = s[i];
            else
                --j;
        }
        return s.substr(0, ++j);
    }
};
