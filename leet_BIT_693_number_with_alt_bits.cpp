class Solution {
public:
    bool hasAlternatingBits(int n)
    {
        int cmp = n % 2;
        while (n)
        {
            if (cmp != n % 2)
                return false;
            cmp = cmp ? 0 : 1;
            n >>= 1;
        }
        return true;
    }
};
