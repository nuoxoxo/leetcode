// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int L = 1, R = n, res = n, M;

    while (L <= R)
    {
        M = L + (R - L) / 2;
        if (isBadVersion(M))
            res = M, R = M - 1;
        else
            L = M + 1;
    }
    return res ;
}
