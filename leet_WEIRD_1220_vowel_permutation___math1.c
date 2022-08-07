
/*
a       e       i               o       u
|       |       |               |       |
e       a, i    a, e, o, u      i, u    a
*/

#define ull unsigned long long

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
        tempa = e % mod;
        tempe = (a + i) % mod;
        tempi = (a + e + o + u) % mod;
        tempo = (i + u) % mod;
        tempu = a % mod;
        a = tempa;
        e = tempe;
        i = tempi;
        o = tempo;
        u = tempu;
    }
    return (a + e + i + o + u) % mod;
}
