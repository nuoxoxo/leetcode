

int divide(int dd, int dv)
{
    long    res = (long) dd / dv;
    if (res > 2147483647)
        return 2147483647;
    return res;
}
