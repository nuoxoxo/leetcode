class Solution {
public:
    int numberOfWays(string corridor)
    {
        int s = 0; // seat counts
        long long res = 1;
        int p = 0; // pls : can put a sep w/in
        int mod = 1e9 + 7;
        for (int c: corridor)
        {
            if (c == 'P')
            {
                if (s > 1 && s % 2 == 0 )
                    p++;
            }
            else if (c == 'S')
            {
                s += 1;
                p %= mod;
                res *= (p + 1);
                res %= mod;
                p = 0;
            }
        }
        if (s % 2 || s < 2)
            return 0;
        return res;
    }
};
