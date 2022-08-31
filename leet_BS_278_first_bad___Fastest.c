// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int l = 1;
    int r = n;
    int res = n;
    int mid;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (isBadVersion(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}
