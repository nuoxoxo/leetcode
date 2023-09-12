class Solution {
public:
    int minDeletions(string s)
    {
        vector<int> e(26, 0);
        int i, pos, len, res;

        len = s.length();
        i = -1;
        while (++i < len)
        {
            pos = s[i] - 'a';
            e[pos]++;
        }
        sort(e.begin(), e.end());
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
