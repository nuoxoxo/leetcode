class Solution {
public:
    bool isIsomorphic(string S, string T)
    {
        vector<char>    ss(255, 0);
        vector<char>    tt(255, 0);
        int             s, t;

        s = -1;
        t = -1;
        while (++s < S.length() && ++t < T.length())
        {
            if (ss[S[s]] && ss[S[s]] != T[t])
                return (false);
            if ( !ss[S[s]] )
            {
                ss[S[s]] = T[t];
                if (tt[T[t]])
                    return (false);
                tt[T[t]] = 1;
            }
        }
        return (true);
    }
};
