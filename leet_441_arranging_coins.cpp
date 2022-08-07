class Solution {
public:
    int arrangeCoins(int n)
    {
        int i = 0;

        while (++i)
        {
            if (i + 1 > n)
                break;
            n -= i;
        }
        if (n == i)
            return i;
        return i - 1;
    }
};
