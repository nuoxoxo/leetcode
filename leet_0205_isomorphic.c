bool isIsomorphic(char* s, char* t)
{
    char mapping[128] = { 0 };
    bool checked[128] = { false };

    while (*s && *t)
    {
        if (mapping[*s] && mapping[*s] != *t)
            return (false);
        if (!mapping[*s] && checked[*t])
            return false;
        mapping[*s] = *t;
        checked[*t] = 1;
        ++s;
        ++t;
    }
    return (true);
}
