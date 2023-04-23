// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n)
{
    return recurse(0, n, n);
}

int recurse(int L, int R, int current)
{
    int         mid;

    if (L > R)
        return current;
    mid = L + (R - L) / 2;
    if (isBadVersion(mid))
    {
        current = mid;
        return recurse(L, mid - 1, current);
    }
    else
    {
        return recurse(mid + 1, R, current);
    }
}
