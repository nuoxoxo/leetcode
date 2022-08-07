char* substr(char *src, int m, int n);

char * longestPalindrome(char * s)
{
    int from = 0, to = 1, i = 0;
    int len = (int) strlen(s);
    int L, R, dist;

    while (++i < len)
    {
        L = i - 1;
        R = i;
        while (R < len && L > -1 && s[L] == s[R])
        {
            dist = R - L + 1;
            if (dist > to)
            {
                to = dist;
                from = L;
            }
            --L;
            ++R;
        }
        L = i - 1;
        R = i + 1;
        while (R < len && L > -1 && s[L] == s[R])
        {
            dist = R - L + 1;
            if (dist > to)
            {
                to = dist;
                from = L;
            }
            --L;
            ++R;
        }
    }
    return (char *) substr(s, from, to);
}

char*   substr(char *src, int start, int len)
{
	char    *res;
	int     i;

	if (!(res = (char *) malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		res[i++] = src[start++];
	res[i] = 0;
	return (char *) (res);
}
