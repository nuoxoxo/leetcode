

bool isIsomorphic(char * s, char * t)
{
    char    ss[255] = { 0 };
    char    tt[255] = { 0 };

    while (*s && *t)
    {
        if (ss[*s] && ss[*s] != *t)
            return (false);
        if ( !ss[*s] )
        {
            ss[*s] = *t;
            if (tt[*t])
                return (false);
            tt[*t] = 1;
        }
        ++s;
        ++t;
    }
    return (true);
}
