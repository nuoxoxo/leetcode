class Solution {
public:
    string finalString(string s)
    {
        string res;
        int r = -1;
        int N = s.length();
        while (++r < N)
        {
            if (s[r] != 'i')
            {
                res += s[r];
                continue ;
            }
            string left;
            int i = -1;
            int L = res.length();
            while (++i < L)
                left += res[L - i - 1];
            res = left;
        }
        return res;
    }
};
