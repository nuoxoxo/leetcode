int compareVersion(char* version1, char* version2)
{

    int size1 = strlen(version1);
    int size2 = strlen(version2);
    int l = 0;
    int r = 0;
    while (l < size1 || r < size2)
    {
        int zero = (int)'0';
        int L = 0;
        int ll = l;
        while (ll < size1 && version1[ll] ^ '.')
        {
            L = L * 10 + (int) (version1[ll] - zero);
            ++ll;
        }
        int R = 0;
        int rr = r;
        while (rr < size2 && version2[rr] ^ '.')
        {
            R = R * 10 + (int) (version2[rr] - zero);
            ++rr;
        }
        if (L > R)
            return 1;
        if (L < R)
            return -1;
        l = ll + 1;
        r = rr + 1;
    }
    return 0;
}

