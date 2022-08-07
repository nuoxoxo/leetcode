

bool checkPossibility(int* n, int len)
{
    int i, two;

    two = i = 0;
    while (++i < len)
    {
        if (n[i - 1] <= n[i])
            continue;
        if (two == 1)
            return 0;
        two += 1;
        if (i > 1)
        {
            if (n[i - 2] == n[i - 1] || n[i - 2] > n[i])
            {
                n[i] = n[i - 1];
            }
            else
            {
                n[i - 1] = n[i - 2];
            }
        }
    }
    return 1;
}
