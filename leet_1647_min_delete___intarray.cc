class Solution {
public:
    int minDeletions(string s)
    {
        int e[26], i, pos, len, res;

        i = -1;
        while (++i < 26)
        {
            e[i] = 0;
        }
        len = s.length();
        i = -1;
        while (++i < len)
        {
            pos = s[i] - 'a';
            e[pos]++;
        }
        int size = sizeof(e) / sizeof(e[0]);    /// obviously 26 but do this by default 
        sort(e, e + size);
        res = 0;
        i = -1;
        while (++i < 25)
        {
            if (e[i] && e[i] == e[i + 1])
            {
                e[i] -= 1;
                res += 1;
                i = -1;
            }
        }
        return res;
    }
};
