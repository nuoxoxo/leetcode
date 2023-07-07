class Solution {
public:
    int numberOfMatches(int n)
    {
        int r = 0;

        while (n)
        {
            r += n / 2;
            n = n / 2 + n % 2;
            if (n == 1)
                break ;
        }
        return r;
    }
};
