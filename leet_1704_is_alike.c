bool halvesAreAlike(char * s)
{
    char    l, r;
    int     n = strlen(s);
    int     ll = 0, rr = 0;
    int     i = -1;
    
    while (++i < n / 2)
    {
        l = s[i];
        r = s[i + n / 2];
        if (l <= 'Z')
            l += 32;
        if (r <= 'Z')
            r += 32;
        if (l == 'a' || l == 'e' || l == 'i' | l == 'o' || l == 'u')
            ++ll;
        if (r == 'a' || r == 'e' || r == 'i' | r == 'o' || r == 'u')
            ++rr;
    }
    return (ll == rr);
}
