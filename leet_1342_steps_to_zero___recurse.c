int solve(int n, int c);

int numberOfSteps(int num)
{
    return solve(num, 0);
}

int solve(int n, int c)
{
    printf("%i, %i\n", n, c);
    if (!n)
        return c;
    if (n % 2)
        return solve(n - 1, c + 1);
    return solve(n / 2, c + 1);
}
