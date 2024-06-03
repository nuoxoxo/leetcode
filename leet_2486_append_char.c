typedef int (* solution)(char *, char *);
int iterative (char *, char *);
int recursive (char *, char *);

int appendCharacters(char* s, char* t) {

    solution Solutions[] = {
        // iterative,
        recursive,
    };
    return Solutions[0](s, t);
}

// func

int iterative (char *s, char *t)
{
    int lens = strlen(s), lent = strlen(t);
    int is = -1, it = 0;
    while (++is < lens)
    {
        if (s[is] == t[it])
        {
            ++it;
            if (it == lent)
                return 0;
        }
    }
    return lent - it;
}

int recursive (char *s, char *t)
{
    return go(s, t, 0, 0);
}

int go(char *s, char *t, int is, int it)
{
    int lens = strlen(s), lent = strlen(t);
    if (it == lent)
        return 0;
    if (is == lens)
        return lent - it;
    if (s[is] == t[it])
        return go(s, t, is + 1, it + 1);
    return go(s, t, is + 1, it);
}
