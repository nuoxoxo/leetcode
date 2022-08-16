

int is_unique(char *s, int idx);

int firstUniqChar(char * s)
{
    int         i = 0;

    while (s[i])
    {
        if (is_unique(s, i))
            return i;
        ++i;
    }
    return -1;
}

int is_unique(char *s, int idx)
{
    char        c = s[idx];
    int         i = 0;

    while (s[i])
    {
        if (i ^ idx && s[i] == c)
            return 0;
        ++i;
    }
    return 1;
}
