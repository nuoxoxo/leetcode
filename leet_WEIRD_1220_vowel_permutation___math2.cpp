
/*

a       e       i               o       u
|       |       |               |       |
e       a, i    a, e, o, u      i, u    a


2nd way to think about it ====>

a       -       e, i, u
e       -       a, i
i       -       e, o
o       -       i
u       -       i, o

*/

#define ull unsigned long long

class Solution {
public:
    int countVowelPermutation(int n)
    {
        ull     a = 1, tempa;
        ull     e = 1, tempe;
        ull     i = 1, tempi;
        ull     o = 1, tempo;
        ull     u = 1, tempu;
        ull     mod = (ull) 1e9 + 7;
        int     k = 1;

        while (++k < n + 1)
        {
            tempa = (e + i + u) % mod;
            tempe = (a + i) % mod;
            tempi = (e + o) % mod;
            tempo = i % mod;
            tempu = (i + o) % mod;
            a = tempa;
            e = tempe;
            i = tempi;
            o = tempo;
            u = tempu;
        }
        return (a + e + i + o + u) % mod;
    }
};
