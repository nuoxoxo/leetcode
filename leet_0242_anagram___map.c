int len(char *);

bool isAnagram(char *s, char *t)
{
    int     ls, lt, i, arr[26];

    ls = len(s);
    lt = len(t);
    if (ls == lt)
    {
        i = -1;
        while (++i < 26)
            arr[i] = 0;
        i = -1;
        while (++i < ls)
        {
            ++arr[s[i] - 'a'];
            --arr[t[i] - 'a'];
        }
        i = -1;
        while (++i < 26)
        {
            if (arr[i])
            {
                printf("%d %d \n", i, arr[i]);
                return false;
            }
        }
        return true;
    }
    return false;
}

int len(char *s)
{
    int         i;

    if (!s)
        return 0;
    i = 0;
    while (s[i] && ++i)
        ;
    return i;
}
