class Solution {
public:
    int smallestRepunitDivByK(int k)
    {
        long long unsigned  r;
        int                 t;

        if ( !(k % 2) || !(k % 5) ) return (-1);
        t = 0;
        r = 1;
        while (++t)
        {
            r %= k;
            if (!r) return (t);
            r = 10 * r + 1;
        }
        return (-1);
    }
};
