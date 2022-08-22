class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if (n < 1)
            return false;
        if (!(n & (n - 1)) && !((n - 1) % 3))
            return true;
        return false;
    }
};
