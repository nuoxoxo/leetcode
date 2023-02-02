int findIndex(char *s, char c);

bool isAlienSorted(char ** words, int wordsSize, char * order)
{
    int i = -1;
    while (++i < wordsSize - 1)
    {
        int Lsize = strlen(words[i]);
        int Rsize = strlen(words[i + 1]);
        int j = -1;
        while (++j < Lsize)
        {
            if (j == Rsize)
                return false;
            if (words[i + 1][j] != words[i][j])
            {
                int Ri = findIndex(order, words[i + 1][j]);
                int Li = findIndex(order, words[i][j]);
                if (Ri < Li)
                    return false ;
                break ;
            }
        }
    }
    return true ;
}

int findIndex(char *s, char c)
{
    int len = strlen(s);
    int i = -1;
    while (++i < len)
    {
        if (s[i] == c)
            return i;
    }
    return -1 ;
}
