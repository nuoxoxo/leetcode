class Solution {
public:
    int numberOfSteps(int n)
    {
        return solve(n, 0);
    }

    int solve(int n, int c)
    {
        if (!n)
            return c;
        if (n % 2)
            return solve(--n, ++c);
        return solve(n / 2, ++c);
    }
};
