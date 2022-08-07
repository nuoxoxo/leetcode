

int lengthOfLongestSubstring(char * s)
{
    if (*s == '\0')
        return 0;
    int set[128];
    int i = -1;
    while (++i < 128)
        set[i] = -1;
    int res = 1, L = 0, R = -1;
    while (s[++R])
    {
        while (set[s[R]] > 0)
        {
            set[s[L]] = -1;
            ++L;
        }
        set[s[R]] = 1;
        int tmp = R - L + 1;
        res = res > tmp ? res : tmp;
    }
    return res;
}
