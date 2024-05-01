char* reversePrefix(char* word, char ch)
{
    int N = strlen(word);
    // char res[N]; // must be malloc'd
    char * res = malloc((N + 1) * sizeof (char));
    if (!res)
        return NULL;
    res[N] = 0;
    int i = -1;
    while (++i < N)
    {
        if (word[i] == ch)
            break ;
    }
    if (i == N)
        return word;
    int index = i++;
    while (--i > -1)
        res[i] = word[index - i];
    while (++index < N)
        res[index] = word[index];
    return res;
}
