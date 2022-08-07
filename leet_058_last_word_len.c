int lengthOfLastWord(char * s)
{
    int     len, i, j;
    
    if (!s[0])  return (0);
    len = i = 0;
    while (s[i])
    {
        j = 0;
        if (!s[i + j])  break;
        while ((s[i + j] <= 'z' && s[i + j] >= 'a') || 
               (s[i + j] <= 'Z' && s[i + j] >= 'A'))
            j++;
        len = j;
        while (s[i + j] == ' ')
            j++;
        i += j;
    }
    return (len);
}
