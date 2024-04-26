int longestIdealString(char* s, int k) {
    int lens[26];
    int i = -1;
    while (++i < 26)
        lens[i] = 0;
    int N = strlen(s);
    i = -1;
    while (++i < N)
    {
        int idx = (int)(s[i] - 'a');
        int L = idx - k;
        int R = idx + k + 1;
        L = L < 0 ? 0 : L;
        R = R > 26 ? 26 : R;
        int best = lens[L];
        int j = L - 1;
        while (++j < R)
        {
            if (best < lens[j])
                best = lens[j];
        }
        lens[idx] = best + 1;
    }
    int best = lens[0];
    i = -1;
    while (++i < 26)
    {
        if (best < lens[i])
            best = lens[i];
    }
    return best;
}
