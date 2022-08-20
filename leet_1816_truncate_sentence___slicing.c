

char * truncateSentence(char * s, int k)
{
    int i = -1;

    while (s[++i])
    {
        if (s[i] == ' ' && --k == 0)
            s[i] = 0;        
    }
    return s;
}
