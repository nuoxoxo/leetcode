

int removePalindromeSub(char * s)
{
    if (!s)
        return 0;
    int i = 0;
    int j = strlen(s) - 1;
    while (i <= j)
    {
        if (s[i] ^ s[j])
            return 2;
        else
        {
            ++i;
            --j;
        }
    }
    return 1;
}
