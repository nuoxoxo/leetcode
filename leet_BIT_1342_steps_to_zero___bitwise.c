

int numberOfSteps(int n)
{
    int c = 0;
    while (n)
    {
        ++c;
        if (n % 2)
            --n;
        else
            n >>= 1;
    }
    return c;
}
