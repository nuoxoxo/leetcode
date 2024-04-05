char* Using_malloc(char* s);

char* makeGood(char* s) {
    return Using_malloc(s);
}

char* Using_malloc(char* s)
{
    int N = strlen(s);
    if (N < 2)
        return s;
    int end = 0;
    char * res = (char *) malloc(sizeof(char) * (N + 1));
    int i = -1;
    while (++i < N)
    {
        res[end] = s[i];
        if (end && (res[end] ^ res[end - 1]) == 32)
            --end;
        else
            ++end;
    }
    res[end] = 0;
    return res;
}

