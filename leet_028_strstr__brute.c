int     strStr(char * haystack, char * needle)
{
        int     h = strlen(haystack);
        int     n = strlen(needle);
        int     i, j;

        if (!n) return (0);
        if (!h || n > h)    return (-1);
        i = 0;
        while (i < h - n + 1)
        {
            j = 0;
            while (haystack[i + j] && haystack[i + j] == needle[j]) j++;
            if (j == n) return (i);
            i++;
        }
        return (-1);
}
